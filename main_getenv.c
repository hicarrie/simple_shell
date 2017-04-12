#include "holberton.h"

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("Value: %s\n", _getenv("HOME"));
	printf("Value: %s\n", _getenv("PATH"));
	printf("Value: %s\n", _getenv("DEFAULTS_PATH"));
	printf("Value: %s\n", _getenv("SHELL"));
	printf("Value: %s\n", _getenv("LS_COLORS"));

	return (0);
}
