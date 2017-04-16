#include "holberton.h"

/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
	char *path;
	char *line;
	char *full_path;
	char **tokens;
	int flag;
	struct stat buf;

	while (TRUE)
	{
		/* check interactive / non-interactive mode */
		prompt(STDIN_FILENO, buf);

		line = _getline(stdin);

		/* check if input == \n */
		if (_strcmp(line, "\n", 1) == 0)
			continue;

		tokens = tokenizer(line);
		if (tokens[0] == NULL)
			continue;

	        builtin_execute(tokens);

		/* search path for executable */
		flag = 0; /* 0 if full_path is not malloc'd */
		path = _getenv("PATH");
		full_path = _which(tokens[0], full_path, path);
		if (full_path == NULL)
			full_path = tokens[0];
		else
			flag = 1; /* if full_path was malloc'd, flag for freeing */

		child(full_path, tokens);

		free_all(tokens, path, line, full_path, flag);
	}
	return (0);
}
