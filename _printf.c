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
	int charcount = 0;
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
					charcount++;
					break;
				case 'i':
					{
						int value = va_arg(list, int);
						char buffer[32];
						int len = snprintf(buffer, sizeof(buffer), "%d", value);
						
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'u':
					{
						unsigned int value = va_arg(list, unsigned int);
						char buffer[32];
						int len = snprintf(buffer, sizeof(buffer), "%u", value);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 's':
					{
						char *value = va_arg(list, char *);
						int len = 0;
						
						while (value[len] != '\0')
						{
							len++;
						}
						write(1, value, len);
						charcount += len;
						break;
					}
				case 'c':
					{
						char value = va_arg(list, int);
						write(1, &value, 1);
						charcount++;
						break;
					}
				case 'd':
					{
						int value = va_arg(list, int);
						char buffer[32];
						int len = snprintf(buffer, sizeof(buffer), "%d", value);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'p':
					{
						void *ptr = va_arg(list, void *);
						char buffer[20];
						int len = snprintf(buffer, sizeof(buffer), "%p", ptr);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'x':
					{
						unsigned int value = va_arg(list, unsigned int);
						char buffer[32];
						int len = snprintf(buffer, sizeof(buffer), "%08X", value);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'X':
					{
						unsigned int value = va_arg(list, unsigned int);
						char buffer[32];
						int len = snprintf(buffer, sizeof(buffer), "%08X", value);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'o':
					{
						unsigned int value = va_arg(list, unsigned int);
						char buffer[32];
						int len = snprintf(buffer, sizeof(buffer), "%o", value);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				default:
					write(1, format - 1, 1);
					write(1, format, 1);
					charcount += 2;
			}
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	va_end(list);
	return (charcount);
}
