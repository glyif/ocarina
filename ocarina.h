#ifndef OCARINA
#define OCARINA
#include "link.h"
void oc_time(void);
int _strcmp(char *s1, char *s2);
char *oc_commands(void);
void add_history(link **head, char *command);
void print_list(link *head);
char *_strcpy(char *dest, char *src);
link *oc_args(char *command);
int oc_exec(link *ocarina, link *history);
int ocarina_command(link *ocarina, link *history);
unsigned int list_len(link *head);
link *get_nodeint_at_index(link *head, unsigned int index);
unsigned int string_int(char *str);
#endif
