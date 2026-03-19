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
	int printed = 0, i = 0;
	va_list args;
	format_t subformat;
	strout_t output;
	char *buffer;

	buffer = malloc(1024);
	if (buffer == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%') /* Write char if not special */
		{
			buffer[printed] = format[i];
			printed++;
			i++;
			continue;
		}
		if (format[i + 1] == '%') /* Write a '%' if escaped */
		{
			buffer[printed] = format[i + 1];
			printed++;
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
		printed += append_to_buffer(&buffer[printed], output.string, output.length);
		free(output.string);
		/** Move i past used format string */
		i += subformat.len;
		continue;
	}
	va_end(args);
	return (write(1, buffer, printed));
}

/**
 * append_to_buffer - Add a string to the _printf buffer
 *
 * @buffer: Pointer to end of used section in buffer
 * @string: String to append
 * @len: Length of string
 * Return: Characters added
 */
int append_to_buffer(char *buffer, char *string, unsigned int len)
{
	unsigned int i = 0;

	while (i < len)
	{
		buffer[i] = string[i];
		i++;
	}
	return (i);
}
