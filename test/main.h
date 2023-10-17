#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
int count(char *);

#endif 
