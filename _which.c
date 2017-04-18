#include "holberton.h"

/**
 * _which - searches directories in PATH variable for command
 * @command: to search for
 * @full_path: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *_which(char *command, char *fullpath, char *path)
{
	unsigned int command_length, path_length, original_path_length;
	char *path_copy;
	char *token;

	command_length = _strlen(command);
	original_path_length = _strlen(path);

	/* make copy of path variable for strtok */
	path_copy = malloc(sizeof(char) * original_path_length + 1);
	if (path_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	_strcpy(path_copy, path);

	/* copy PATH directory + command name and check if it exists */
	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_length = _strlen(token);

		fullpath = malloc(sizeof(char) * (path_length + command_length) + 2);
		if (fullpath == NULL)
		{
			errors(3);
			return (NULL);
		}

		_strcpy(full_path, token, path_length);
		full_path[path_length] = '/';
		_strcpy(full_path + path_length + 1, command, command_length);
		full_path[path_length + command_length + 1] = '\0';

		/* if directory + command exists, stop iterating and return */
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_copy);
	return (fullpath);
}
