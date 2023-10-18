#include "main.h"

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
	char *buffer = (char *)malloc(BUFFER_SIZE);
	int leng;
	
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
						int len = snprintf(buffer, BUFFER_SIZE, "%d", value);
						
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'u':
					{
						unsigned int value = va_arg(list, unsigned int);
						int len = snprintf(buffer, BUFFER_SIZE, "%u", value);
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
						char *value = va_arg(list, char *);
						int len = snprintf(buffer, BUFFER_SIZE, "%d", value);
						write(1, &len, sizeof(int));
						write(1, buffer, len);
						charcount += len;
                                                break;
					}
				case 'p':
					{
						void *ptr = va_arg(list, void *);
						int len = snprintf(buffer, BUFFER_SIZE, "%p", ptr);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'x':
					{
						unsigned int value = va_arg(list, unsigned int);
						int len = snprintf(buffer, BUFFER_SIZE, "%08X", value);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'X':
					{
						unsigned int value = va_arg(list, unsigned int);
						int len = snprintf(buffer, BUFFER_SIZE, "%08X", value);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				case 'o':
					{
						unsigned int value = va_arg(list, unsigned int);
						int len = snprintf(buffer, BUFFER_SIZE, "%o", value);
						write(1, buffer, len);
						charcount += len;
						break;
					}
				default:
					write(1, format - 1, 1);
					write(1, format, 1);
					charcount++;
			}
		}
		else
		{
			write(1, format, 1);
			charcount += leng && 1;
		}
		format++;
	}
	free(buffer);
	va_end(list);

	return (charcount);
}
