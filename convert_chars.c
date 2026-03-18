#include "main.h"
/**
 * convert_undefined - Return attempted format substring
 *
 * @substring: Pointer to substring
 * @len: Length of substring
 * Return: Undefined format substring
 */
char *convert_undefined(const char *substring, unsigned int len)
{
	unsigned int i = 0;
	char *out = malloc(len + 1);

	if (out == NULL)
		exit(-1);
	while (i < len)
	{
		out[i] = substring[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/**
 * convert_char - Convert char from arg into string
 *
 * @args: Arguments from _printf with char next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to new string
 */
char *convert_char(va_list args, format_t format)
{
	char *out = malloc(2);
	(void) format;

	if (out == NULL)
		exit(-1);
	out[0] = va_arg(args, int);
	out[1] = '\0';
	return (out);
}

/**
 * convert_str - Copy a string from arg to be editable
 *
 * @args: Arguments from _printf with char next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to new string
 */
char *convert_str(va_list args, format_t format)
{
	char *out;
	char *data = va_arg(args, char *);
	int i = 0;
	(void) format;

/* handle NULL value */
if (data == NULL)
data = "(null)";

while (data[i] != '\0')
i++;
out = malloc(i + 1);
if (out == NULL)
exit(-1);
i = 0;
while (data[i] != '\0')
{
out[i] = data[i];
i++;
}
out[i] = '\0';

return (out);
}
