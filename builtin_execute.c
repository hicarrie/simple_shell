#include "holberton.h"
/**
**builtin_execute - executes the built in functions
**@tokens: arguments being passed
**Return: tokens
**/
int builtin_execute(char **tokens)
{
	int i;
	
	if (tokens[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (_strcmp(tokens[0], builtin_str[i]) == 0)
	{
		return (*builtin_func[i])(tokens);
	}
}	



/**
**shell_num_builtins - this check num built-ins
**Return: num of built-ins
**/

int shell_num_builtins()
{
	return (sizeof(builtin_str) / sizeof(char *);
}
