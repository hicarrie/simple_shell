#include "holberton.h"

/**
 * strtok - tokenizes string
 * @str: user input
 * @tokens: pointer to array of tokenized input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str, char **tokens)
{
	char *token;
	unsigned int i;

	token = strtok(str, "\n\t\r ");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
