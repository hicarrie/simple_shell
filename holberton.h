#ifndef LINKED_H
#define LINKED_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


typedef struct list_s
{
	char *name;
	char *value;
	struct list_s *next;
} list_s;

char **_strtok(char *str);
char *_getline(FILE *fp);
char *_which(char *command);
int _strlen(char *s);
void _puts(char *str);

/*prototypes for the helper functions for PATH linked list*/
list_s *path_list(char *variable);
size_t list_len(const list_s *h);
list_s *add_node(list_s **head, const char *str);
list_s *add_node_end(list_s **head, const char *str);


#endif /* HOLBETON_H */
