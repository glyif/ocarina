#include "ocarina.h"
#include <stdio.h>

int ocarina_command(char **args, link *ocarina)
{
	int i;

	link *tmp;

	tmp = ocarina;
  	
	if (args[1] == NULL)
	{
		return (0);
  	}
  	else
  	{
		if(_strcmp(args[1], "prev") == 0)
		{
			while(i < 3)
				tmp = tmp->next;
			
			printf("%s\n", tmp->command);

			
		}
  	}

  	return 1;
}
