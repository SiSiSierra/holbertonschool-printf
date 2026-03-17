#include "main.h"
#include <stdio.h>

/**
 * get_format_length - Determine the length of format substring for _printf
 *
 * @format: Pointer to beginning of format substring
 * Return: Length of substring
 */
int get_format_length(const char *format)
{
	char specifiers[11] = {'c', 's', 'd', 'i', 'b',
		'u', 'o', 'x', 'X', 'p', 'S'};
	int i = 0;
	int j;
	int length = 0;

	while (format[i] != '\0')
	{
		length++;
		j = 0;
		while (j < 11)
		{
			if (format[i] == specifiers[j])
				return (length);
			j++;
		}
		i++;
	}
	return (length);
}

/**
 * get_conv_func - Determine and use correct data conversion
 *
 * @format: Pointer to specifier in format
 * Return: Pointer to function that converts a data type to string
 */
char *get_conv_func(const char *format, va_list args)
{
	/** Variables */
	/** List of conversion specifiers and their functions */
	convert_t conversions[] = {
		{'d', convert_int},
		{'i', convert_int},
		{'c', convert_char},
		{'s', convert_str}
	};
	int i = 0;

	/** Go through format looking for conversion specifier */
	while (conversions[i].specifier != format[0])
		i++;
	return (conversions[i].f(args));
}
