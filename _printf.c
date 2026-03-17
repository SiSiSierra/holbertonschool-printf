#include "main.h"

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
	int printed = 0;
	int i = 0;
	va_list args;

	/** Code */
	va_start(args, format);
	/** Loop until format is terminated */
	while (format[i] != '\0')
	{
		/** If character is ordinary, print normally */
		if (format[i] != '%')
		{
			printed += write(1, &format[i], 1);
			i++;
			continue;
		}
		/** Check if conversion is actually escape for '%' in output */
		if (format[i + 1] == '%')
		{
			printed += write(1, &format[i + 1], 1);
			i += 2;
			continue;
		}
		i++;
		continue;
	}
	/** End */
	return (printed);
}
