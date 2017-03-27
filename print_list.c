#include <stdio.h>
#include "ocarina.h"

void print_list(link *head)
{
	while (head != NULL)
	{	
		printf("%d: %s\n", head->index, head->command);
		head = head->next;
	}
}
