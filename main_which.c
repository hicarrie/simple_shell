#include "holberton.h"

/**
 * main - prints full directory path of given command
 * Return: 0
 */
int main(void)
{
	char *path;
	char *full_path = NULL;

	path = _which("ls", full_path);

	printf("%s\n", path);

	free(full_path);

	return (0);
}
