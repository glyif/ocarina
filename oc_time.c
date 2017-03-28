#include <stdio.h>
#include <stdlib.h>
#include "ocarina.h"

void oc_time(void)
{
	char *commands;

	int commands_len;
	int exit_status;

	commands_len = 0;

	link *head;
	link *args;
	link *sep;
	args = NULL;
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

		sep = oc_args(&args, commands);

		add_history(&head, commands);

		print_list(head);

		exit_status = oc_exec(sep);

		free(commands);
	} while (exit_status == 0);
}
