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
	int printed = 0;
	int i = 0;
	int j;
	va_list args;
	format_t subformat;
	char *output;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%') /* Write char if not special */
		{
			printed += write(1, &format[i], 1);
			i++;
			continue;
		}
		if (format[i + 1] == '%') /* Write two '%' if escaped */
		{
			printed += write(1, &format[i + 1], 1);
			i += 2;
			continue;
		}
		subformat = get_subformat(&format[i]);
		output = get_conv_func(&format[i] + subformat.length - 1, args, subformat);
		j = 0;
		while (output[j] != '\0')
		{
			printed += write(1, &output[j], 1);
			j++;
		}
		free(output);
		/** Move i past used format string */
		i += subformat.length;
		continue;
	}
	va_end(args);
	return (printed);
}
