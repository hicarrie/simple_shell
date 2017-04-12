#include "holberton.h"
/**
**
**
**/

	int shell_exit(void)
	{
	        return (0);
	}

	int shell_env(void)
	{
		unsigned int i;
		extern char **environ;

		i = 0;
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (0);
	}
