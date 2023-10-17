#include "main.h"

/**
 * count- the string counter
 * @str: string
 *
 * Return: int i.
 */

int count(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
