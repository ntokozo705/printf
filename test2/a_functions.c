#include "main.h"
/**
 * printnum - function to count numbers
 * @n: recursively added number
 * Return: void
 */

int printnum(int n)
{
	int count = 0;
    unsigned int a, fig, num;
	unsigned int len_mun;

	len_mun = n;
	if (n < 0)
	{
		count++;
		len_mun = len_mun * -1;
		_putchar('-');
	}
	if (len_mun == 0)
	{
		count++;
		_putchar('0');
		return (count);
	}
        a = 1;
    
	while (((len_mun / a) > 9))
	{
		a = a * 10;
	}
	while (a > 0)
	{
		num = len_mun / a;
		fig = num % 10;
		count++;
		_putchar(fig + '0');
		a = (a / 10);
	}
	return (count);
}

/**
 * print_d - prints integers, decimals numbers
 * @list: list
 * Return: number
 */

int print_d(va_list list)
{
	int count;
    int op;

	op = va_arg(list, int);
	count = printnum(op);
	return (count);
}

/**
 * print_r - prints a reverse
 * @list: list
 * Return: reversed string
 */

int print_r(va_list list)
{
	char *cat = "%r";
	int len = _strlen(cat);

	write(1, cat, len);
	va_end(list);
	return (len);
}

/**
 * _strlen - Checks how long is a string
 * @s: String
 * Return: length of string, 0
 */

int _strlen(char *e)
{
	if (*e == '\0')
	{
		return (0);
	}
		else
	{
		return (1 + _strlen(e + 1));
	}
}

/**
 * print_c - prints a char
 * @list: list
 * Return: char
 */

int print_c(va_list list)
{
	char c;

	c = va_arg(list, int);
	_putchar(c);
	return (0);
}
/**
 * print_s - prints string
 * @list: list
 * Return: string
 */

int print_s(va_list list)
{
	int a;
	char *str2;

	str2 = va_arg(list, char *);

	if (str2 == NULL)
	{
		_printf("(null)");
		return (6);
	}
	for (a = 0; str2[a] != '\0'; a++)
		_putchar(str2[a]);
	return (a);
}
/**
 * print_mod - prints % symbol
 * @list: list
 * Return: % symbol
 */

int print_indi(va_list list)
{
	if (list != NULL)
	{
	}
	_putchar('%');
	return (0);
}
