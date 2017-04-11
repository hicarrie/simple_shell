#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "

typedef struct token
{
	char *token;
	struct token *next;
} token_t;

typedef struct path
{
	char *dir;
	struct path *next;
} path_t;

typedef struct env
{
	char *name;
	char *value;
	struct env *next;
} env_t;

int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strtoupper(char *s);
char *_strcat(char *dest, char *src);
char *_getline(FILE *fp);
char **_strtok(char *str);
void _puts(char *str);
void _printenv(void);
char *_getenv(const char *name);
char *_strstr(const char *name, char *variable);
char *path_print(void);
path_t *path_list(char *variable);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *_which(char *command);

#endif /* HOLBERTON_H */
