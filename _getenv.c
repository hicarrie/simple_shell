#include "holberton.h"

/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *variable;
	char *value;
	int compare;
	unsigned int length;
	unsigned int i;

	length = _strlen((char *)name);
	i = 0;
	while (environ[i] != NULL)
	{
		variable = environ[i];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, " ");
			return (value);
		}
		i++;
	}
	return (NULL);
}
