#include "ocarina.h"
#include <stdio.h>
#include <stdlib.h>

int oc_exec(link *ocarina, link *history)
{
	int i;

	link *tmp;

	router route[] = {
		{"ocarina", ocarina_command},
		{NULL, NULL}
	};

	tmp = ocarina;

	for (i = 0; route[i].command != NULL; i++)
		if (_strcmp(route[i].command, tmp->command) == 0)
			return route[i].f(ocarina, history);

	return (0);
}
