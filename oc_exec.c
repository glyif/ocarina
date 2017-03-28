#include "ocarina.h"
#include <stdio.h>
#include <stdlib.h>

int oc_exec(link *ocarina)
{
	int i;

	link *tmp;

	tmp = ocarina;

	router route[] = {
		{"ocarina", ocarina_command},
		{NULL, NULL}
	};

	if (_strcmp(route[0].command, tmp->command) == 0)
		printf("hi\n\n");

	return (0);
}
