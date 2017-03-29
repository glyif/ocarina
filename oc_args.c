#include "ocarina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

link *oc_args(link **head, char *command)
{
	int c;
	int i, j, spaces, distance;
	char *str;

	link *sep;
	sep = NULL;

	i = 0;
	j = 0;
	distance = 0;
	spaces = 0;

	while (command[i] != '\0')
	{
		if (command[i] == ' ')
		{
			spaces++;
		}
		i++;
	}

	spaces++;

	i = 0;

	while (spaces > 0)
	{
		if (command[i] == ' ' || command[i] == '\0')
		{
			distance = (i - j) + 1;
			str = malloc(sizeof(char) * distance);
			
			c = 0;

			while(j < i)
			{
				str[c] = command[j];
				c++;
				j++;
			}
			
			add_history(&sep, str);

			j = i + 1;

			spaces--;
			
		}

		i++;
	}

	return (sep);

}
