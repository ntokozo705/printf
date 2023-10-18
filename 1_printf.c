#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * _printf - the function prototype
 * @format - the holder for arg
 * @...: more arguments
 *
 * Return: int number of char.
 */

int _printf(const char *format, ...)
{
	int charcount = 0;
	va_list list;
	char *buffer = (char *)malloc(BUFFER_SIZE);
	char *bufptr = buffer;
	int bufsize = 0;

	if (format == NULL)
	{
		free(buffer);
		return (-1);
	}
	va_start(list, format);
	while (*format)
	{
		if (bufsize >= BUFFER_SIZE - 1)
		{
			write(1, buffer, bufsize);
			charcount += bufsize;
			bufsize = 0;
			bufptr = buffer;
		}
		if (*format == '%')
		{
			format++;
		switch (*format)
		{
			case '%':
				*bufptr = '%';
				bufptr++;
				bufsize++;
				break;
			case 'i':
				{
					int value = va_arg(list, int);
					int len = snprintf(bufptr, BUFFER_SIZE - bufsize, "%d", value);
					bufptr += len;
					bufsize += len;
					break;
				}
			case 'u':
				{
					unsigned int value = va_arg(list, unsigned int);
					int len = snprintf(bufptr, BUFFER_SIZE - bufsize, "%u", value);
					bufptr += len;
					bufsize += len;
					break;
				}
			case 's':
				{
					char *value = va_arg(list, char *);
					while (*value)
					{
						*bufptr = *value;
						bufptr++;
						bufsize++;
						value++;
					}
						break;
				}
			case 'c':
				{
					char value = va_arg(list, int);
					*bufptr = value;
					bufptr++;
					bufsize++;
					break;
				}
			case 'd':
				{
					int value = va_arg(list, int);
					int len = snprintf(bufptr, BUFFER_SIZE - bufsize, "%d", value);
					bufptr += len;
					bufsize += len;
					break;
				}
			case 'b':
				{
					unsigned int value = va_arg(list, unsigned int);
					int i;
					for (i = 31; i >= 0; i--)
					{
						*bufptr = (value & (1 << i)) ? '1' : '0';
						bufptr++;
						bufsize++;
					}
					break;
				}
			case 'S':
				{
					char *value = va_arg(list, char *);
					while (*value)
					{
						if (*value < 32 || *value >= 127)
						{
							char buffer[5];
							int len = snprintf(buffer, sizeof(buffer), "\\x%02X", *value);
							bufptr += len;
							bufsize += len;
						}
						else
						{
							*bufptr = *value;
							bufptr++;
							bufsize++;
						}
						value++;
					}
					break;
				}
			case 'p':
				{
					void *ptr = va_arg(list, void *);
					int len = snprintf(bufptr, BUFFER_SIZE - bufsize, "%p", ptr);
					bufptr += len;
					bufsize += len;
					break;
				}
			case 'x':
				{
					unsigned int value = va_arg(list, unsigned int);
					int len = snprintf(bufptr, BUFFER_SIZE - bufsize, "%08x", value);
					bufptr += len;
					bufsize += len;
					break;
				}
			case 'X':
				{
					unsigned int value = va_arg(list, unsigned int);
					int len = snprintf(bufptr, BUFFER_SIZE - bufsize, "%08X", value);
					bufptr += len;
					bufsize += len;
					break;
				}
			case 'o':
				{
					unsigned int value = va_arg(list, unsigned int);
					int len = snprintf(bufptr, BUFFER_SIZE - bufsize, "%o", value);
					bufptr += len;
					bufsize += len;
					break;
				}
			default:
				--format;
				*bufptr = *format;
				bufptr++;
				bufsize++;
				charcount++;
		}
		}
	else
	{
		*bufptr = *format;
		bufptr++;
		bufsize++;
	}
	format++;
	}
	write(1, buffer, bufsize);
	charcount += bufsize;
	free(buffer);
	va_end(list);
	return (charcount);
}
