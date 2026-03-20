#include "main.h"

/**
 * convert_undefined - Return attempted format substring
 *
 * @substring: Pointer to substring
 * @len: Length of substring
 * Return: Undefined format substring
 */
strout_t convert_undefined(const char *substring, unsigned int len)
{
	unsigned int i = 0;
	strout_t out;

	out.length = len;
	out.string = malloc(len);
	if (out.string == NULL)
		exit(-1);
	while (i < len)
	{
		out.string[i] = substring[i];
		i++;
	}
	return (out);
}

/**
 * convert_char - Convert char from arg into string
 *
 * @args: Arguments from _printf with char next in line
 * @format: Struct containing formatting arguments
 * Return: String and length
 */
strout_t convert_char(va_list args, format_t format)
{
	strout_t out;
	int i;

	out = get_buffer(format.width, 1);
	if (format.flags.left)
		i = 0;
	else
		i = out.length - 1;
	out.string[i] = va_arg(args, int);
	pad_buffer(out.string, 1, format);
	return (out);
}

/**
 * convert_str - Copy a string from arg to be editable
 *
 * @args: Arguments from _printf with char next in line
 * @format: Struct containing formatting arguments
 * Return: String and length
 */
strout_t convert_str(va_list args, format_t format)
{
	char *data = va_arg(args, char *);
	strout_t out;
	int i = 0;
	(void) format;

	/* handle NULL value */
	if (data == NULL)
		data = "(null)";

	while (data[i] != '\0')
		i++;
	out.string = malloc(i + 1);
	if (out.string == NULL)
		exit(-1);
	i = 0;
	while (data[i] != '\0')
	{
		out.string[i] = data[i];
		i++;
	}
	out.length = i;
	return (out);
}

/**
 * reverse_str - return reversed string
 *
 * @args: Arguments from _printf with string next in line
 * @format: Struct containing formatting arguments
 * Return: String and length
 */
strout_t reverse_str(va_list args, format_t format)
{
	strout_t out;

	out = convert_str(args, format);
	reverse_string_helper(out.string, out.length);
	return (out);
}

/**
 * convert_rot13 - return string after rot13 cipher
 *
 * @args: Arguments from _printf with string next in line
 * @format: Struct containing formatting arguments
 * Return: String and length
 */
strout_t convert_rot13(va_list args, format_t format)
{
	strout_t out;
	unsigned int i = 0;

	out = convert_str(args, format);
	while (i < out.length)
	{
		if (out.string[i] >= 'A' && out.string[i] <= 'Z')
		{
			if (out.string[i] <= 'M')
				out.string[i] += 13;
			else
				out.string[i] -= 13;
		} else if (out.string[i] >= 'a' && out.string[i] <= 'z')
		{
			if (out.string[i] <= 'm')
				out.string[i] += 13;
			else
				out.string[i] -= 13;
		}
		i++;
	}
	return (out);
}
