#include <stdio.h>
#include <stdlib.h>
#include "ocarina.h"

void oc_time(void)
{
	char *commands;
	char *commandscpy;
	char *exit_status;
	char **args;

	int commands_len;

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

		commands_len = _strlen(commands);

		commandscpy = malloc(commands_len * sizeof(char));

		commandscpy = _strcpy(commandscpy, commands);
		
		args = oc_args(commands);

		add_history(&head, commandscpy);

		print_list(head);

		free(commands);
	} while (exit_status == 0);
}
