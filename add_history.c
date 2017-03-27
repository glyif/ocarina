#include "ocarina.h"
#include <string.h>
#include <stdlib.h>

void add_history(link **head, char *command)
{
    link *new, *last;
	int i;

	i = 0;

	new = malloc(sizeof(link));
 
	last = *head;

    new->command = strdup(command);

	if (new->command == NULL)
		return;
 
    new->next = NULL;
 
    if (*head == NULL)
    {
        new->prev = NULL;
        *head = new;
        return;
    }

	i = 1;
 
    while (last->next != NULL)
	{
        last = last->next;
		i++;
	}
 
    last->next = new;
 
    new->prev = last;

	new->index = i;	
    return;
}
