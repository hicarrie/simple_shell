#include "holberton.h"
/**
**builtin_execute - executes the built in functions
**@tokens: arguments being passed
**Return: tokens
**/
int builtin_execute(char **tokens)
{
	int i;
	int (*shell_exit)(void);
	int (*shell_env)(void);

	/* char *builtin_str[] =
	{
		"exit",
		"env"
	};

	int (*builtin_func[])(void) =
	{
		&shell_exit,
		&shell_env
		}; */

	/* struct of function pointers */

	if (tokens[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < shell_num_builtins(builtin_str); i++)
	{
		if (_strcmp(tokens[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(void);
	}
	return (0);
}



/**
**shell_num_builtins - this check num built-ins
**Return: num of built-ins
**/

int shell_num_builtins(char **str)
{
	return (sizeof(str) / sizeof(char **));
}
