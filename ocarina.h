#ifndef OCARINA
#define OCARINA
#include "link.h"
void oc_time(void);
int _strcmp(char *s1, char *s2);
char *oc_commands(void);
void add_history(link **head, char *command);
void print_list(link *head);
char *oc_tokenize(char *str, const char *delim);
char *_strcpy(char *dest, char *src);
char **oc_args(char *command);
#endif
