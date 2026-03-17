#include "main.h"
#include <unistd.h>

/**
 * _printf - Print a string of characters using specified format
 *
 * @format: Buffer containing chars and format specifiers
 * Return: Number of characters printed
 *
 * Format can be a buffer of any set of characters, but
 * "%" indicates a format specifier and following
 * valid format characters will be replaced depending
 * on the format
 */
int _printf(const char *format, ...)
{
/** Variables */
int count = 0;

if (format == NULL)
return (-1);

/** Code */
while (format[count] != '\0')
{
write(1, &format[count], 1);
count++;
}

/** End */
return (count);
}

