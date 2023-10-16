#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int _printf(const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);

/**
 * struct ye - operations structure
 * @ma: operation
 * @g: will be provided
 * 
 * Description: Checking operation 
 */

typedef struct ye
{
	char *ma;
	int (*g)(va_list);
}ye_g;

int h_function(const char *format, ye_g ma[], va_list za);
int _strlen(char *e);
int print_c(va_list list);
int print_s(va_list list);
int print_d(va_list list);
int print_d(va_list list);
int print_indi(va_list list);
int print_r(va_list list);
int _putchar(char c);

#endif 
