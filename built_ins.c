#include "holberton.h"


	int shell_exit(char **args);
	void shell_env(void);

	char *built_in_str[] = 
	{
		"exit",
		"env"
	};

	int (*built_in_func[]) (char **) = 
	{
		&shell_exit,
		&shell_env
	};

	int shell_exit(char **args)
	{
		return 0;
	}

	void print_env(void)
	{
		unsigned int i;
		extern char **environ;

		i = 0;
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			i++
		}
}	
	
