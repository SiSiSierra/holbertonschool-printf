#include "main.h"
#include <stdio.h>
/**
 * convert_int - Convert an int into a string
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_int(va_list args, format_t format)
{
	int data = va_arg(args, int); /* get int from arg list */
	long i = 0, tmp = data, tmp2 = data;
	int len = 0, sign = 0;
	strout_t out;

	if (tmp < 0) /* convert tmp to positive and store sign */
	{
		tmp = -tmp;
		sign = 1;
	}
	tmp2 = tmp;
	if (format.flags.plus)
		sign = 1;
	if (tmp == 0)
		len++;
	while (tmp > 0) /* find len of number */
	{
		tmp /= 10;
		len++;
	}
	out = get_buffer(format.width, len + sign); /* allocate mem for buffer */
	if (!format.flags.left)
		i = out.length - 1;
	else
		i = len + sign - 1;
	if (data == 0)
		out.string[i] = '0';
	for (i = i; tmp2 > 0; i--) /* add number in reverse */
	{
		out.string[i] = (tmp2 % 10) + '0';
		tmp2 /= 10;
	}
	if (format.flags.pad)
	{
		i = 0;
		pad_buffer(out.string, len, format);
	} else
		pad_buffer(out.string, len + sign, format);
	if (data < 0)
		out.string[i] = '-';
	else if (sign)
		out.string[i] = '+';
	return (out);
}

/**
 * convert_int_to_bi - Convert an unsigned int into binary
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_bi(va_list args, format_t format)
{
unsigned int n = va_arg(args, unsigned int);
unsigned int tmp = n;
int bits = 0, bit = 0, i = 0;
strout_t out;
(void) format;

if (n == 0) /* handle 0 case */
return (handle_zero_case());

while (tmp > 0) /* calc num of bits required to store n in binary */
{
tmp = tmp >> 1;
bits++;
}

out.length = bits; /* get length of str */
out.string = malloc(bits); /* allocate memory */
if (out.string == NULL)
exit(-1);

/* fill str starting from highest to lowest binary */
for (i = bits - 1; i >= 0; i--)
{
bit = (n >> i) & 1; /* shift right and keep last digit, bitwise operation */
out.string[bits - (i + 1)] = bit + '0';
}

return (out); /* return */
}
