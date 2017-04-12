#include "holberton.h"

/**
 * main - prints full directory path of given command
 * Return: 0
 */
int main(void)
{
	char *path;

	path = _which("ls");

	printf("%s\n", path);

	return (0);
}
