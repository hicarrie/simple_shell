#include "holberton.h"

/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	char **tokens = NULL;
	char *full_path;
	char *path;
	ssize_t read;
	size_t len = 0;
	int status, flag;
	int execve_status;
	int builtin_status;
	struct stat buf;
	pid_t child_pid;

	while (TRUE)
	{
		/* check interactive / non-interactive mode */
		prompt(STDIN_FILENO, buf);

		/* get input from user */
		line = NULL;
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		/* check if input == \n */
		if (_strcmp(line, "\n", 1) == 0)
			continue;

		/* tokenize input */
		tokens = malloc(sizeof(char) * BUFFER);
		if (tokens == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		tokens = _strtok(line, tokens);
		if (tokens[0] == NULL)
			continue;

		/* check for builtins */
		builtin_status = builtin_execute(tokens);
		if (builtin_status == 0)
			exit(EXIT_SUCCESS);

		/* check PATH for executables */
		flag = 0;
		path = _getenv("PATH");
		full_path = _which(tokens[0], full_path, path);
		if (full_path == NULL)
			full_path = tokens[0];
		else
			flag = 1; /* if full_path was malloc'd, flag for freeing */

		/* create child process to run executables */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			execve_status = execve(full_path, tokens, NULL);
			if (execve_status == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}

		}
		else
			wait(&status);

		/* free everything! */
		free(path);
	        free(tokens);
		free(line);
		if (flag == 1)
			free(full_path);

	}

	return (0);
}
