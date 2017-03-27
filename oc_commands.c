#include <stdlib.h>
#include <stdio.h>

char *oc_commands(void)
{
	char *buffer;
	char *tmp;
	int index;
	int buff_size;
	int new_buff_size;
	int c;
	int multiplier;
	int i;

	buff_size = 1024;

	buffer = malloc(buff_size);
	index = 0;
	multiplier = 2;

	if (buffer == NULL)
		return (NULL);

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[index] = '\0';
			return (buffer);
		}
		else
		{
			buffer[index] = c;
		}

		index++;

		if (index >= buff_size)
		{
			tmp = malloc(buff_size);

			for (i = 0; i <= buff_size; i++)
				tmp[i] = buffer[i];

			free(buffer);

			new_buff_size = buff_size * multiplier;

			buffer = malloc(new_buff_size);
			
			if (buffer == NULL)
				return (NULL);

			for(i = 0; i <= buff_size; i++)
				buffer[i] = tmp[i];

			buff_size = new_buff_size;
			
			free(tmp);

			multiplier++;
		}
	}

	printf("%s", buffer);
}
