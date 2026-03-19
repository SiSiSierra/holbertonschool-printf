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
	va_list args;
	format_t subformat;
	strout_t output;

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
		if (format[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		subformat = get_subformat(&format[i]);
		output = get_conv_func(&format[i] + subformat.len - 1, args, subformat);
		printed += write(1, output.string, output.length);
		free(output.string);
		/** Move i past used format string */
		i += subformat.len;
		continue;
	}
	va_end(args);
	return (printed);
}
