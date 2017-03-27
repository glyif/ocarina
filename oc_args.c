#include "ocarina.h"
#include <stdlib.h>

char **oc_args(char *command)
{
	int max_arg;
	int index;
	char **args;
	char *arg;

	max_arg = 10;

	args = malloc(sizeof(*args) * max_arg);

	if (args == NULL)
		return (NULL);

	arg = oc_tokenize(command, " ");

	index = 0;
	while (arg != NULL)
	{
		args[index] = arg;
		index++;

		arg = oc_tokenize(command, " ");
	}

	args[index] = NULL;

	return (args);
}
