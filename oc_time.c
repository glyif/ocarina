#include <stdio.h>
#include <stdlib.h>
#include "ocarina.h"

void oc_time(void)
{
	char *commands;

	int exit_status;

	link *head;
	link *sep;
	head = NULL;
	exit_status = 0;

	do
	{
		printf("ocarina > ");
		commands = oc_commands();
		
		if (commands == NULL)
		{
			printf("Error\n");
			return;
		}

		sep = oc_args(commands);

		add_history(&head, commands);

		exit_status = oc_exec(sep, head);

		free(commands);
	} while (exit_status == 0);
}
