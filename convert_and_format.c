#include "main.h"

/**
 * convert_and_format - Convert a _printf argument into string as specified
 *
 * @format: Pointer to beginning of format and conversion specifier
 * @args: va_list containing data to convert
 * Return: Pointer to complete formatted string
 */
char *convert_and_format(char *format, va_list args)
{
	void(format);
	void(args);
	return ("Attempted to convert and format");
}

/**
 * get_conv_func - Determine which conversion to use
 *
 * @format: Pointer to beginning of format
 * Return: Pointer to function that converts a data type to string
 */
char *(*get_conv_func(char *format))(va_list)
{
	/** Variables */
	/** List of conversion specifiers and their functions */
	convert_t conversions[] = {
		{"d", convert_int},
		{"i", convert_int},
		{NULL, NULL}
	};
	int i = 0;
	int j;

	/** Go through format looking for conversion specifier */
	while (format[i] != '\0')
	{
		/** Compare to specifiers in conversions list */
		j = 0;
		while (conversions[j].specifier != NULL)
		{
			if (*conversions[j].specifier == format[i])
				return (conversions[j].f);
			j++;
		}
		i++;
	}
	/** If nothing is found, be sad */
	return (NULL);
}
