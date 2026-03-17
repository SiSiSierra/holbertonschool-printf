#include "main.h"
/**
 * convert_char - Convert char from arg into string
 *
 * @args: Arguments from _printf with char next in line
 * Return: Pointer to new string
 */
char *convert_char(va_list args)
{
	char *out = malloc(2);

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
 * Return: Pointer to new string
 */
char *convert_str(va_list args)
{
	char *out;
	char *data = va_arg(args, char *);
	int i = 0;

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
