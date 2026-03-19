#include "main.h"

/**
 * get_subformat - Determine every component of a format substring
 *
 * @format: Pointer to beginning of format substring
 * Return: Complete format_t struct
 */
format_t get_subformat(const char *format)
{
	format_t subformat = {{0, 0, 0, 0, 0}, 0, 0, 'a', 0};
	int i = 1; /** 0 is the '%' icon starting the substring */

	while (format[i] != '\0') /** First look for flags */
	{
		if (get_flag(format[i], &subformat.flags) == 1)
			break;
		i++;
	}
	if (format[i] >= '0' && format[i] <= '9') /** Second look for width */
		i += get_num(&format[i], &subformat.width);
	if (format[i] == '.') /** Third look for precision */
	{
		i++;
		i += get_num(&format[i], &subformat.precision);
	}
	if (format[i] == 'l' || format[i] == 'h') /** Fourth look for length mod */
	{
		subformat.length_mod = format[i];
		i++;
	}
	subformat.len = i + 1;

	return (subformat);
}

/**
 * get_flag - Extract the flag from pointed character
 *
 * @format: Char to check
 * @subformat: Pointer to struct containing flags to use later
 * Return: 0 if a flag was found, 1 if no flag, 2 if duped flag
 */
int get_flag(const char format, flags_t *subformat)
{
	if (format == '#')
		subformat->alternate += 1;
	else if (format == '0')
		subformat->pad += 1;
	else if (format == '-')
		subformat->left += 1;
	else if (format == ' ')
		subformat->space += 1;
	else if (format == '+')
		subformat->plus += 1;
	else
		return (1);
	return (0);
}

/**
 * get_num - Extract a number from string
 *
 * @format: Pointer to beginning of number in string
 * @subformat: Member in format struct to change
 * Return: Length of number in string
 */
int get_num(const char *format, unsigned int *subformat)
{
	unsigned int len = 0;
	unsigned int number = 0;

	while (format[len] >= '0' && format[len] <= '9')
	{
		number *= 10;
		number += format[len] - '0';
		len++;
	}
	*subformat = number;
	return (len);
}


/**
 * get_conv_func - Determine and use correct data conversion
 *
 * @specifier: Pointer to specifier in format
 * @args: va_list to pass to conversion function
 * @format: Struct of formatting flags to pass to func
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
		{'X', convert_unsigned_to_base_16_X},
		{'r', reverse_str},
		{'R', convert_rot13},
		{(char)0, NULL} /** Sentinel value, keep last */
	};
	int i = 0;
	/** Go through format looking for conversion specifier */
	while (*specifier != conversions[i].specifier && conversions[i].f != NULL)
		i++;
	if (conversions[i].f == NULL)
		return (convert_undefined(specifier - format.len + 1, format.len));
	return (conversions[i].f(args, format));
}
