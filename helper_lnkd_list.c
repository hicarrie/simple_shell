#include "holberton.h"

/**
**helper_functions - these are helper functions for linked list
**/

/**
**free_list - free the list
**@head: head of the nodes or start of them
**Return: void
**
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
/*
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
	} */

/**
**delete_nodeint_at_index - deletes node at start.
**@head:arg
**@index:arg
**Return: 1 or -1
**/
/*
int delete_nodeint_at_index(list_s **head, unsigned int index)
{
	unsigned int i;
	list_s *tmp, *after;

	tmp = *head;

	if (head == NULL || *head == NULL)
	return (-1);

	if (index == 0)
	{
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	for (i = 0; i < index - 1 && tmp != NULL; i++)
		tmp = tmp->next;

	after = tmp->next;
	tmp->next = after->next;
	free(after);
	return (1);
	} */

/**
**change_node_value - change the value for a particular name
** @name: name of node
** @value: new value
**Return: 1 on success, -1 on failure
**/
