#include "main.h"



/**
 * convert_int - Convert an int into a string
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */
strout_t convert_int(va_list args, format_t format)
{
	int data = va_arg(args, int), len = 0, sign = 0;
	long i = 0, j, tmp = data, tmp2 = data;
	strout_t out;

	if (tmp < 0 || format.flags.space || format.flags.plus) /** Check for prefix*/
		sign = 1;
	if (tmp == 0)
		len++;
	if (tmp < 0)
		tmp = -tmp;
	tmp2 = tmp;
	for (tmp = data; tmp != 0; tmp /= 10) /* find len of number */
		len++;
	if (len < format.precision)
		len += format.precision - len;
	out = get_buffer(format.width, len + sign);
	if (!format.flags.left)
		i = out.length - len - sign;
	if (data == 0)
		out.string[i] = '0';
	i = i + len + sign - 1;
	for (j = 0; j < len; j++) /* add number in reverse */
	{
		out.string[i] = (tmp2 % 10) + '0';
		tmp2 /= 10;
		i--;
	}
	pad_buffer(out.string, len + sign, format);
	if (format.flags.pad)
	{
		out.string[i] = '0';
		i = 0;
	}
	if (data < 0)
		out.string[i] = '-';
	else if (format.flags.plus)
		out.string[i] = '+';
	else if (format.flags.space)
		out.string[i] = ' ';
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
