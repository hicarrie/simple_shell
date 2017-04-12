#include "holberton.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: string to be appended
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++, j++)
		dest[j] = src[i];

	dest[j] = '\0';

	return (dest);
}
