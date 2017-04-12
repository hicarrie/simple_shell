#include "holberton.h"

/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	char **tokens;
	int status;
	pid_t child_pid;
	struct stat buf;
	unsigned int length;
	int builtin_status;

	while (TRUE)
	{
		fstat(STDIN_FILENO, &buf);

		if (S_ISFIFO(buf.st_mode))
			;
		else if (S_ISCHR(buf.st_mode))
			_puts(PROMPT);

		line = _getline(stdin);
		if (line == NULL)
			return (0);

		length = _strlen(line);

		line[length - 1] = '\0';

		tokens = _strtok(line);

		builtin_status = builtin_execute(tokens);

		if (builtin_status == 0)
			exit(EXIT_SUCCESS);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			status = execve(tokens[0], tokens, NULL);
			if (status == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}

	free(line);
	free(tokens);

	return (0);
}
