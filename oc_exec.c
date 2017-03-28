#include "ocarina.h"
#include <stdlib.h>

int oc_exec(char **args, link *ocarina)
{
	int i;

	router route[] = {
		{"ocarina", ocarina_command},
		{NULL, NULL}
	};

	for (i = 0; route[i].command != NULL; i++)
		if (_strcmp(args[0], route[i].command) == 0)
			return (route[i].f(args, ocarina));

	return (0);
}
