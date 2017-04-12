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

typedef struct list_s
{
	char *name;
	char *value;
	struct list_s *next;
} list_s;

int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char **_strtok(char *str);
char *_strcat(char *dest, char *src);
char *_getline(FILE *fp);
char *_getenv(const char *name);
char *_which(char *command);
void _puts(char *str);
void _printenv(void);

/* prototypes for builtins */

int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(char **str);

/* prototypes for the helper functions for PATH linked list */
list_s *path_list(char *variable);
size_t list_len(const list_s *h);
list_s *add_node(list_s **head, const char *str);
list_s *add_node_end(list_s **head, const char *str);

#endif /* HOLBERTON_H */
