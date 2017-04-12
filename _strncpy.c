#include "holberton.h"

/**
 * *_strncpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strncpy(char *dest, char *src, unsigned int length)
{
	unsigned int i;

	for (i = 0; i < length; i++)
		dest[i] = src[i];

	return (dest);
}
