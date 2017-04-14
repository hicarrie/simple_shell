#include "holberton.h"

/**
 * which - searches directories in PATH variable for command
 * @command: to search for
 * @full_path: full path of command to execute
 * Return: pointer to full_path
 */
char *_which(char *command, char *full_path)
{
	char *path;
	unsigned int command_length;
	unsigned int path_length;
	char *token;
	struct stat buf;

	path = _getenv("PATH");

	command_length = _strlen(command);

	token = strtok(path, ":");
	while (token != NULL)
	{
		path_length = _strlen(token);

		full_path = malloc(sizeof(char) * (path_length + command_length + 2));
			if (full_path == NULL)
				return (NULL);

	        _strncpy(full_path, token, path_length);
	        full_path[path_length] = '/';
	        _strncpy(full_path + path_length + 1, command, command_length);
		full_path[path_length + command_length + 1] = '\0';

		if (stat(full_path, &buf) == 0)
			break;
		else
		{
			free(full_path);
			full_path = NULL;
			token = strtok(NULL, ":");
		}
	}

	return (full_path);
}
