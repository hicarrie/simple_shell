#include "holberton.h"

/**
 * which - searches directories in PATH variable for command
 * @command: command to search for
 * Return: full path name of command
 */
char *_which(char *command)
{
	char *path;
        list_s *list;
	list_s *current;
	char *full_path;
	struct stat buf;

	full_path = malloc(sizeof(char) * BUFFER);
	if (full_path == NULL)
		return (NULL);

	path = _getenv("PATH");

	list = path_list(path);

	current = list;

	while (current->next != NULL)
	{
		if (current->dir == NULL)
			;
		else
		{
			full_path = _strcat(current->dir, "/");
			full_path = _strcat(full_path, command);
			if (stat(full_path, &buf) == 0)
				return (full_path);
		}
		current = current->next;
	}
	return (NULL);
}
