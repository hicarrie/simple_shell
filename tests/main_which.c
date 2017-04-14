#include "holberton.h"

/**
 * main - prints full directory path of given command
 * Return: 0
 */
int main(void)
{
	char *full_path = NULL;

	full_path = _which("ls", full_path);

	printf("Path: %s\n", full_path);

	free(full_path);

	return (0);
}
