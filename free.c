#include "holberton.h"

/**
 * free_dp - free double pointer
 * @array: double pointer to free
 * @length: length of double pointer
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 *free_list - free the list
 *@head: head of the nodes or start of them
 *Return: void
 */
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
