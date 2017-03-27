#include "ocarina.h"
#include <stdlib.h>
#include <string.h>

char **oc_args(char *command)
{
	int buffsize;
	int index;
	char **args;
	char *arg;
	char *str;

	buffsize = 100;
	index = 0;
	
	args = malloc(sizeof(char *) * buffsize);

	if (args == NULL)
		return (NULL);

  	arg = strtok(command, " ,.-");
  
	while (arg != NULL)
	{
    	args[index] = arg;
		index++;
    	arg = strtok(NULL, " ,.-");
  	}
  
	args[index] = NULL;
  
	return args;
}
