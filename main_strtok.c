#include "holberton.h"

/**
 * main - uses strtok to print tokens
 * @ac: number of arguments
 * @av: pointer to array of strings
 * Return: 0 on success
 */
int main(void)
{
	char *str;
	char **tokens;
	unsigned int i;

	str = _getline(stdin);

	tokens = _strtok(str);

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]);
		i++;
	}

	return (0);
}
