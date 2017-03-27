/**
 * _strcmp - compares string
 * @s1: first string
 * @s2: second string
 *
 * Return: difference between two ascii valuves
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return ((int) s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strcpy - copy string
 * @dest: copy of src
 * @src: the source of the copy
 *
 * Return: the copy of the src
 */

char *_strcpy(char *dest, char *src)
{
	char *temp = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	return (temp);
}

/**
 * _strlen - length of a string
 * @str: string
 *
 * Return: length of the string
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;

	return (i);
}
