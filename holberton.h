#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "

/*
 * struct list_s - linked list of variables
 * @name: name
 * @value: value
 * @next: pointer to next node
 * Description: generic linked list struct for variables
 */
typedef struct list_s
{
	char *name;
	char *value;
	struct list_s *next;
} list_s;

/*
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 * Description: struct for builtin functions
 */
typedef struct built_s
{
        char *name;
	int (*p)(void);
}built_s;
/*
 * struct main_s - struct to contain information on shell 
 * @env: pointer to environment
 * @path_list: pointer to function
 * @args: pointer to arguments being passed
 * Description: struct for builtin functions
 */
typedef struct main_s
{
	char **env;
	list_t *path_list;
	char **args;
	
}main_t





char *_getline(FILE *fp, char *line);
char *_which(char *command, char *full_path);

/* utility functions */
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char **_strtok(char *str, char **tokens);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, unsigned int length);

/* prototypes for builtins */
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);

/* prototypes for the helper functions for variable linked lists */
char *_getenv(const char *name);
char **env_copy(char **env_copy);
list_s *path_list(char *variable, list_s *head);
void free_list(list_s *head);

#endif /* HOLBERTON_H */
