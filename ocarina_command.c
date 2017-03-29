#include "ocarina.h"
#include <stdio.h>

int ocarina_command(link *ocarina, link *history)
{
	link *tmp;
	link *recall_history;
	int integer;
	int counter;
	int i;

	i = 0;
	stop = list_len(history);
	counter = list_len(history);
	tmp = get_nodeint_at_index(ocarina, 1);

	if (tmp == NULL)
	{
		printf("not enought arguments\n");
	}
	else if (_strcmp(tmp->command, "prev") == 0)
	{
		counter--;
		recall_history = get_nodeint_at_index(history, counter);
		if (counter < 0)
			printf("that's all folks");
		else
			printf("%s\n", recall_history->command);
	}
	else
	{
		integer = string_int(tmp->command);
		recall_history = get_nodeint_at_index(history, integer);
		
		if (recall_history == NULL)
			printf("history doesn't go back that long\n");
		else
			printf("%s\n", recall_history->command);
	}
	return 0;
}
