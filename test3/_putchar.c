#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes char c 
 * @c: printed character
 * Return: 0 (success), 1 (error)
 */ 

int _putchar(char c)
{
    return (write(1, &c, 1));
}
