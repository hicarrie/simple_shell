#include "holberton.h"
/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
	char *line, *path, *fullpath;
	char **tokens;
	int flag, builtin_status, child_status;
	struct stat buf;

	while (TRUE)
	{
		/* check interactive / non-interactive mode */
		prompt(STDIN_FILENO, buf);
		line = _getline(stdin);
		/* check if input == \n */
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}

		tokens = tokenizer(line);
		if (tokens[0] == NULL)
			continue;

		builtin_status = builtin_execute(tokens);
		if (builtin_status == 0)
			continue;

		/* search path for executable */
		flag = 0; /* 0 if full_path is not malloc'd */
		path = _getenv("PATH");
		fullpath = _which(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1; /* if full_path was malloc'd, flag for freeing */

		child_status = child(fullpath, tokens);
		if (child_status == -1)
			errors(2);
		free_all(tokens, path, line, fullpath, flag);
	}
	return (0);
}
