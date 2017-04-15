#include "holberton.h"

/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name, char **environ_copy)
{
	char *variable;
	char *value;
	int compare;
	unsigned int length;
	unsigned int i;

	/* make copy of global environment variable */
	length = 0;
	while (environ[length] != NULL)
		length++;

	environ_copy = malloc(sizeof(char **) * (length));
	if (environ_copy == NULL)
		return (NULL);

	environ_copy = env_copy(environ_copy, length);

	length = _strlen((char *)name);

	/* iterate through environment variable until given name is found */
	i = 0;
	while (environ_copy[i] != NULL)
	{
		variable = environ_copy[i];
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

/**
 * env_copy - copies environment variable
 * @env_copy: pointer to copy of environment variable
 * Return: double pointer to copy of environment variable
 */
char **env_copy(char **env_copy, unsigned int length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	i = 0;
	while (i < length)
	{
		variable = environ[i];
		variable_length = _strlen(variable);

		env_copy[i] = malloc(variable_length + 1);
		if (env_copy[i] == NULL)
			return (NULL);

		_strcpy(env_copy[i], environ[i]);
		i++;
	}

	return (env_copy);
}
