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
	printf("Before free_list\n");
	free_list(list);
	printf("After free_list\n");
	return (return_path);
}

/**
 * free_list - frees a list_s list
 * @head: list to be freed
 * Return: void
 */
void free_list(list_s *head)
{
	list_s *current;

	while (head != NULL)
	{
		current = head;
		printf("Before iterating to next node\n");
		head = head->next;
		printf("Before freeing current->name\n");
		free(current->name);
		printf("Before freeing current->value\n");
		free(current->value);
		printf("Before freeing node\n");
		free(current);
	}
}
