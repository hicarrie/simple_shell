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


typedef struct built_s
{
        char *name;
	int (*p)(void);
}built_s;


int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char **_strtok(char *str, char **tokens);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, unsigned int length);
char *_getline(FILE *fp, char *line);
char *_getenv(const char *name);
char *_which(char *command, char *full_path);
void _puts(char *str);
void _printenv(void);

/* prototypes for builtins */

int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);

/* prototypes for the helper functions for PATH linked list */
char **env_copy(char **env_copy);
list_s *path_list(char *variable, list_s *head);
void free_list(list_s *head);
size_t list_len(const list_s *h);
list_s *add_node(list_s **head, const char *str);
list_s *add_node_end(list_s **head, const char *str);

#endif /* HOLBERTON_H */
