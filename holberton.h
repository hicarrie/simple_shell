#ifndef LINKED_H
#define LINKED_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>




prompt(void) __attribute__((constructor));

typedef struct list_s
{
	char *name;
	char *value;
	struct list_s *next;
} list_t;

char **_strtok(char *str);
int _strlen(char *s);
void _puts(char *str);
char *_getline(FILE *fp);

/*prototypes for the helper functions for PATH linked list*/
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);


#endif
