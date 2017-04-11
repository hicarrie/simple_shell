#include "holberton.h"

/**
 * strtok - tokenizes string
 * Return: pointer to array of tokens
 */
char **_strtok(char *str)
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
		exit(0);

	token = strtok(str, " ");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
