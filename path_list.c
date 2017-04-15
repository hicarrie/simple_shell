#include "holberton.h"

/**
 * path_list - separates PATH variable into tokens and puts into linked list
 * @variable: pointer to PATH variable
 * @head: start of node
 * Return: pointer to head of linked list of path variables
 */
list_s *path_list(char *variable, list_s *head)
{
	list_s *new;
	list_s *current;
	char *token;

	head = NULL;
	token = strtok(variable, ":");
	while (token != NULL)
	{
		current = head;

		new = malloc(sizeof(list_s));
		if (new == NULL)
			return (NULL);

		new->name = "";
		new->value = token;
		new->next = NULL;

		if (head == NULL)
			head = new;
		else
		{
			while (current->next != NULL)
				current = current->next;

			current->next = new;
		}

		token = strtok(NULL, ":");
	}

	return (head);
}
