#include "holberton.h"

/**
 * child - function for child process
 * @fullpath: full path of executable
 * @tokens: tokenized user input
 * Return: 0 on success
 */
int child(char *fullpath, char **tokens)
{
	pid_t child_pid;
	int status;
	int execve_status;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_status = execve(fullpath, tokens, envp);
		if (execve_status == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
