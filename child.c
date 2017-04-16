#include "holberton.h"

/**
 * child - function for child process
 * @full_path: full path of executable
 * @tokens: tokenized user input
 * Return: 0 on success
 */
int child(char *full_path, char **tokens)
{
	pid_t child_pid;
	int status;
	int execve_status;

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

	return (0);
}
