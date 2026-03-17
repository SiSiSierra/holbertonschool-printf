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
	int printed = 0;
	int i = 0;
	int j;
	va_list args;
	int format_length;
	char *output;

	/** Code */
	va_start(args, format);

	/** Loop until format is terminated */
	while (format[i] != '\0')
	{
        /* If char is not a format spec, write char */
		if (format[i] != '%')
		{
			printed += write(1, &format[i], 1);
			i++;
			continue;
		}

        /* handle %% case */
		if (format[i + 1] == '%')
		{
			printed += write(1, &format[i + 1], 1);
			i += 2;
			continue;
		}

		format_length = get_format_length(&format[i]);
		output = get_conv_func(&format[i + format_length - 1], args);

		/** Format converted using formatting */
		/** output = format(output) */
		/** Write final string out */
		j = 0;

		while (output[j] != '\0')
		{
			printed += write(1, &output[j], 1);
			j++;
		}
		/** Move i past used format string */
		i += format_length;
		continue;
	}

    va_end(args);
	/** End */
	return (printed);
}
