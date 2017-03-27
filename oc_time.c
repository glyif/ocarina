#include <stdio.h>
#include <stdlib.h>
#include "ocarina.h"

void oc_time(void)
{
	char *commands;
	char *exit_status;
	link *head;
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

		add_history(&head, commands);

		print_list(head);

		free(commands);
	} while (exit_status == 0);
}
