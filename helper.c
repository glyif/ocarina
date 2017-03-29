#include "ocarina.h"
#include <stdlib.h>

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

/**
 * list_len - length of a list
 * @head: head of the list
 * Return: length of the list
 */
unsigned int list_len(link *head)
{
	int i;

	for (i = 0; head->next != NULL; i++)
		head = head->next;

	return (i);
}

/**
 * get_nodeint_at_index - fetches a node at a given point
 * @head: head of a list
 * @index: index of where to add node
 *
 * Return: struct pointer to new node
 */

link *get_nodeint_at_index(link *head, unsigned int index)
{
	link *tmp;

	unsigned long len, i;

	tmp = head;

	len = list_len(tmp);

	if (len < index)
		return (NULL);

	for (i = 0; i < index; i++)
		tmp = tmp->next;

	if (i == index)
		return (tmp);
	else
		return (NULL);

}

unsigned int string_int(char *str)
{
	int len, i, num;

	len = _strlen(str);

	num = 0;

	for (i = 0; i < len; i++)
		num = num * 10 + ( str[i] - '0' );

	return (num);
}
