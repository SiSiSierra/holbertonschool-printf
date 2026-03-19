#include "main.h"

/**
 * get_subformat - Determine every component of a format substring
 *
 * @format: Pointer to beginning of format substring
 * Return: Complete format_t struct
 */
format_t get_subformat(const char *format)
{
	format_t subformat = {{0, 0, 0, 0, 0}, 0, 0, 0};
	int i = 1; /** 0 is the '%' icon starting the substring */

	while (format[i] != '\0') /** First look for flags */
		break;
	while (format[i] != '\0') /** Second look for width */
		break;
	while (format[i] != '\0') /** Third look for precision */
		break;
	subformat.length = i + 1;

	return (subformat);
}

/**
 * get_conv_func - Determine and use correct data conversion
 *
 * @specifier: Pointer to specifier in format
 * Return: Converted string
 */
strout_t get_conv_func(char const *specifier, va_list args, format_t format)
{
	/** Variables */
	/** List of conversion specifiers and their functions */
	convert_t conversions[] = {
		{'d', convert_int},
		{'i', convert_int},
		{'c', convert_char},
		{'s', convert_str},
		{'b', convert_unsigned_to_bi},
		{'u', convert_unsigned_to_base_10},
		{'o', convert_unsigned_to_base_8},
		{'x', convert_unsigned_to_base_16},
		{(char)0, NULL} /** Sentinel value, keep last */
	};
	int i = 0;
	/** Go through format looking for conversion specifier */
	while (*specifier != conversions[i].specifier && conversions[i].f != NULL)
		i++;
	if (conversions[i].f == NULL)
		return(convert_undefined(specifier - format.length + 1, format.length));
	return (conversions[i].f(args, format));
}
