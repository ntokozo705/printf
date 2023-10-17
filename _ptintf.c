#include "main.h"
/**
 * _printf - prints based on format
 * @format: format of the function
 * cases - c, s, d, %, i, r
 * Return: a string.
 */
int _printf(const char *format, ...)
{
	va_list za;
	int charcount = -1;

	ye_g ma[] = {
	{"c", print_c},
	{"s", print_s},
	{"d", print_d},
	{"%", print_indi},
	{"i", print_d},
	{"r", print_r},
	{NULL, NULL}
	};

	if (format != NULL)
	{
		va_start(za, format);
		charcount = h_function(format, ma, za);
		va_end(za);
	}
	return (charcount);
}

/**
 * h_function - helping function to print and call other functions
 * @format: format of function
 * @ma: special option
 * @za: arguments
 * Return: count printed char
 */

int h_function(const char *format, ye_g ma[], va_list za)
{
	int charcount = 0;
    int a;
    int k;

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] == '%')
		{
			if (format[a + 1] == '\0')
			{
				return (-1);
			}
			for (k = 0; ma[k].ma != NULL; k++)
			{
				if (format[a + 1] == ma[k].ma[0])
				{
					charcount = charcount + ma[k].g(za);
					break;
				}
			}
			if (ma[k].ma == NULL && format[a + 1] != ' ')
			{
				if (format[a + 1] != '\0')
				{
					_putchar(format[a]);
					_putchar(format[a + 1]);
					charcount = charcount + 2;
				}
				else
					return (-1);
			}
			a = a + 1;
		}
		else
		{
			_putchar(format[a]);
			charcount = charcount + 1;
		}
	}
	return (charcount);
}
