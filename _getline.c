#include "holberton.h"

/**
 * _getline - gets string from stdin
 *@fp: taking in the use input
 *@line: storing user input
 *Return: pointer to string
 */
char *_getline(FILE *fp, char *line)
{
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, fp);
	if (read == -1)
		return (NULL);

	return (line);
}
