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
	char *return_path = NULL;
	unsigned int command_length;
	unsigned int path_length;
	struct stat buf;

	path = _getenv("PATH");
	printf("path: %s\n", path);

	list = path_list(path);
	printf("Address of list: %p\n", (void *)list);

	command_length = _strlen(command);

	current = list;

	while (current->next != NULL) /* segfault */
	{
		printf("Address of next node: %p\n", (void *)current->next);
		if (current->value == NULL)
			;
		else
		{
			path_length = _strlen(current->value);

			full_path = malloc(sizeof(char) * (path_length + command_length + 1));
			if (full_path == NULL)
				return (NULL);

			full_path = _strcat(current->value, "/");
			full_path = _strcat(full_path, command);

			if (stat(full_path, &buf) == 0)
			{
				return_path = full_path;
				break;
			}
		}
		current = current->next;
		printf("Current->value: %s\n", current->value);
	}

	free_list(list);
	return (return_path);
}
