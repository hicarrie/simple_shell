#include "holberton.h"

/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
	char **environ_copy = NULL;
	char *variable;
	char *value;
	int compare;
	unsigned int length;
	unsigned int i;

	environ_copy = env_copy(environ_copy);

	length = _strlen((char *)name);
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
 * _copyenv - copies environment variable
 * @env_copy: pointer to copy of environment variable
 * Return: double pointer to copy of environment variable
 */
char **env_copy(char **env_copy)
{
	extern char **environ;
	char *variable;
	unsigned int variable_length;
	unsigned int length;
	unsigned int i;

	length = 0;
	while (environ[length] != NULL)
		length++;

	env_copy = malloc(sizeof(char **) * (length));
	if (env_copy == NULL)
		return (NULL);

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
