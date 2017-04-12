#include "holberton.h"

/**
 * main - uses path_list to put PATH directories in linked list
 * Return: Always 0.
 */
int main(void)
{
	char *path;
	list_s *list;
	list_s *current;

	path = _getenv("PATH");

	list = path_list(path);

	current = list;

	while (current->next != NULL)
	{
		printf("%s\n", current->value);
		current = current->next;
	}

	return (0);
}
