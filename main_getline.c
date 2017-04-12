#include "holberton.h"

/**
 * main - uses getline and prints line
 * @ac: number of arguments
 * @av: pointer to array of strings
 * Return: 0
 */
int main (int ac, char *av[])
{
	char *line;

	line = _getline(stdin);

	printf("%s\n", line);

	return (0);
}
