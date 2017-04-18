#include "holberton.h"

/**
 * _getline - puts input from user into buffer line
 * @fp: buffer for user input
 * Return: buffer with user input
 */
char *_getline(FILE *fp)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, fp);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
