#include "holberton.h"

/**
 * main - prints ppid
 * Return: 0 on success
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getppid();

	printf("%u\n", my_pid);

	return (0);
}
