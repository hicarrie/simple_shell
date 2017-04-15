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
	char *path;
	int compare;
	unsigned int path_length;
	unsigned int environ_length;
	unsigned int length;
	unsigned int i;

	environ_length = 0;
	while (environ[environ_length] != NULL)
		environ_length++;
	environ_copy = copy_env(environ_copy, environ_length);

	/* iterate through environment variable until given name is found */
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

			path_length = _strlen(value);
			path = malloc(sizeof(char) * path_length + 1);
			path = _strcpy(path, value);

			free_dp(environ_copy, environ_length);

			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * env_copy - copies environment variable
 * @env_copy: pointer to copy of environment variable
 * @environ_length: length of environment variable
 * Return: double pointer to copy of environment variable
 */
char **copy_env(char **environ_copy, unsigned int environ_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	environ_copy = malloc(sizeof(char **) * (environ_length));
	if (environ_copy == NULL)
		return (NULL);

	i = 0;
	while (i < environ_length)
	{
		variable = environ[i];
		variable_length = _strlen(variable);

		environ_copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (environ_copy[i] == NULL)
			return (NULL);

		_strcpy(environ_copy[i], environ[i]);
		i++;
	}

	return (environ_copy);
}
