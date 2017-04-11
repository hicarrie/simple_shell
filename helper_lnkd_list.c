#include "shell.h"
/**
**helper_functions - these are helper functions for linked list
**/

/**
**free_list - free the list
**@head: head of the nodes or start of them
**Return: void
**
**/
void free_list(list_t *head)
{
	list_t *free_list;
	
	if (head == NULL)
		return;

	while (head != NULL)
	{
		free_list = head;
		head = head->next;
		free(free_list->str);
		free(free_list);
	}
}



/**
**add_node_end - returns # of elements in the end of  linked list
**@head: pointer to the linked lists
**@str: the string
**Return: # of nodes in the linked list
**/
list_t *add_node_end(list_t **head, const char *str)
{

	list_t *last_node;
	list_t *new_node;

	new_node = *head;

	last_node = malloc(sizeof(list_t));
	if (last_node == NULL)
	{
		return (NULL);
	}

	last_node->str = strdup(str);
	last_node->len = _strlen(str);
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
/**
**_strlen - function returns the length of a string.
**@s: variable
**Description: returns length
**Return: variable
**/
int _strlen(const char *s)
{
	int i;

	i = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
	i++;

	return (i);
}


/**
**delete_nodeint_at_index - deletes node at start.
**@head:arg
**@index:arg
**Return: 1 or -1
**/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *tmp, *after;

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
}

/**
**change_node_value - change the value for a particular name
** @name: name of node
** @value: new value
**Return: 1 on success, -1 on failure
**/
