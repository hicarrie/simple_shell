#include "holberton.h"

/**
 * prompt - checks mode and prints prompt if in interactive mode
 * @fd: file stream
 * @buf: buffer
 * Return: 0 on success
**/
int prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);

	return (0);
}
