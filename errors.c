#include "holberton.h"

/**
 * errors - prints errors based on case
 * @case_num: error number associated with perror statement
 * Return: void
 */
void errors(int error)
{
	switch(error)
	{
	case 1: /* writes fork error to stderr */
		write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
		perror("Error");
		break;

	case 2: /* writes execve error to stderr */
		write(STDERR_FILENO, ERR_EXECVE, _strlen(ERR_EXECVE));
		perror("Error");
		break;

	case 3: /* writes malloc error to stderr */
	        write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
		break;

	default:
		return;
	}

	return;
}
