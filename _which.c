#include "holberton.h"

/**
 * which - searches directories in PATH variable for command
 * @command: command to search for
 * Return: full path name of command
 */
char *_which(char *command, char *full_path)
{
	char *path;
        list_s *list = NULL;
	list_s *current;
	unsigned int command_length;
	unsigned int path_length;
	struct stat buf;

	path = _getenv("PATH");

	list = path_list(path, list);

	command_length = _strlen(command);

	current = list;

	while (current->next != NULL)
	{
		if (current->value == NULL)
			;
		else
		{
			path_length = _strlen(current->value);

			full_path = malloc(sizeof(char) * (path_length + command_length + 2));
			if (full_path == NULL)
				return (NULL);

		        _strncpy(full_path, current->value, path_length);
		        full_path[path_length] = '/';
		        _strncpy(full_path + path_length + 1, command, command_length);
			full_path[path_length + command_length + 1] = '\0';

			if (stat(full_path, &buf) == 0)
				break;
			else
				full_path = NULL;
		}
		current = current->next;
	}

	free_list(list);
	return (full_path);
}
