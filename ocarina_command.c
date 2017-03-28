#include "ocarina.h"
#include <stdio.h>

int ocarina_command(link *ocarina)
{
	int i;

	link *tmp;

	tmp = ocarina;
  	
	for (i = 0; i < 2; i++)
		tmp = tmp->next;

	if (tmp->command == NULL)
	{
		return (0);
  	}
  	else
  	{
  		printf("This enters the ocarina command\n");
	}

  	return 1;
}
