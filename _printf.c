#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - the print if function creation
 * @format: the string capture
 *
 * Return: counter.
 */

int _printf(const char *format, ...)
{
	int charprint = 0;
	va_list list;
	
	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case '%':
					write(1, format, 1);
					break;
				case 's':
					{
						char *value = va_arg(list, char *);
						int len = 0;
						
						while (value[len] != '\0')
						{
							len++;
						}
						write(1, value, len);
						break;
					}
				case 'c':
					{
						char value = va_arg(list, int);
						write(1, &value, 1);
						break;
					}
				default:
					write(1, "UNKNOWN_FORMAT_SPECIFIER: %", 26);
					write(1, format, 1);
			}
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	va_end(list);
	return (charprint);
}
