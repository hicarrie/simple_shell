#include "holberton.h"

/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	char **tokens = NULL;
	char *full_path;
	int status;
	int builtin_status;
	struct stat buf;
	pid_t child_pid;
	unsigned int length;

	while (TRUE)
	{
		/* check interactive / non-interactive mode */
		fstat(STDIN_FILENO, &buf);

		if (S_ISFIFO(buf.st_mode))
			;
		else if (S_ISCHR(buf.st_mode))
			_puts(PROMPT);

		/* get input from user */
		line = _getline(stdin, line);
		if (line == NULL)
			return (0);

		/* remove newline character from input */
		length = _strlen(line);
		line[length - 1] = '\0';

		/* tokenize input */
		tokens = malloc(sizeof(char) * BUFFER);
		if (tokens == NULL)
			exit(0);

		tokens = _strtok(line, tokens);

		/* check for builtins */
		builtin_status = builtin_execute(tokens);
		if (builtin_status == 0)
			exit(EXIT_SUCCESS);

		/* check PATH for executables */
		full_path = _which(tokens[0], full_path);
		if (full_path == NULL)
			full_path = tokens[0];

		/* create child process to run executables */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			status = execve(full_path, tokens, NULL);
			if (status == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);

		free(line);
		free(tokens);
		free(full_path);
	}

	return (0);
}
