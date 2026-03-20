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
	strout_t out = {NULL, 1};
	(void) format;

	out.string = malloc(1);
	if (out.string == NULL)
		exit(-1);
	out.string[0] = va_arg(args, int);
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
	(void) format;
	return malloc_cpy_str(data);

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
