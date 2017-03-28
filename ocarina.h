#ifndef OCARINA
#define OCARINA
#include "link.h"
void oc_time(void);
int _strcmp(char *s1, char *s2);
char *oc_commands(void);
void add_history(link **head, char *command);
void print_list(link *head);
char *_strcpy(char *dest, char *src);
void oc_args(link *head, char *command);
int oc_exec(char **args, link *ocarina);
int ocarina_command(char **args, link *ocarina);
#endif
