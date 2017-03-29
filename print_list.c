#include <stdio.h>
#include "ocarina.h"

void print_list(link *head)
{
	int i;
	link *tmp;

	tmp = head;

	for (i = 0; tmp != NULL; i++)
	{	
		printf("%d: %s\n", tmp->index, tmp->command);
		tmp = tmp->next;
	}
}
