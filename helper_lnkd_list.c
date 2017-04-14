#include "holberton.h"
/**
**free_list - free the list
**@head: head of the nodes or start of them
**Return: void
**/
void free_list(list_s *head)
{
	list_s *current;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}



/**
**add_node_end - returns # of elements in the end of  linked list
**@head: pointer to the linked lists
**@str: the string
**Return: # of nodes in the linked list
**/
list_s *add_node_end(list_s **head, const char *str)
{
	list_s *last_node;
	list_s *new_node;

	new_node = *head;

	last_node = malloc(sizeof(list_t));
	if (last_node == NULL)
	{
		return (NULL);
	}

	last_node->name = strdup(str);
	last_node->value = _strlen(str);
	last_node->next = NULL;

	if (*head == NULL)
	{
		*head = last_node;
		return (last_node);
	}

	while (new_node->next != NULL)
		new_node = new_node->next;

	new_node->next = last_node;
	return (last_node);
}
