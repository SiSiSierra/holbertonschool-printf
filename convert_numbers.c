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
	int n = va_arg(args, int); /* get int from arg list */
	long i = 0, tmp = n, num = n;
	int len = 0, negative = 0;
	strout_t out;
	(void) format;

	if (n == 0) /* handle zero case*/
	{
		out.string = malloc(1);
		if (out.string == NULL)
			exit(-1);
		out.string[0] = '0';
		out.length = 1;
		return (out);
	}
	if (tmp < 0) /* convert tmp to positive and store sign */
	{
		tmp = -tmp;
		negative = 1;
	}
	num = tmp;
	while (tmp > 0) /* find len of number */
	{
		tmp /= 10;
		len++;
	}
	out.string = malloc(len + negative); /* allocate mem for buffer */
	if (out.string == NULL)
		exit(-1);
	for (i = 0; num > 0; i++) /* add number in reverse */
	{
		out.string[i] = (num % 10) + '0';
		num /= 10;
	}
	if (negative == 1) /* add negative sign*/
	{
		len++;
		out.string[i++] = '-';
	}
	reverse_string(out.string, i); /* reverse str in place */;
	out.length = len;
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
int bit = 0, len = 0;
strout_t out;
(void) format;

/* handle 0 case */
if (n == 0)
{
out.string = malloc(1);
if (out.string == NULL)
exit(-1);
out.string[0] = '0';
out.length = 1;
return (out);
}

/* find highest bit and therefore length*/
while (tmp > 0)
{
tmp = tmp >> 1;
bits++;
}

out.length = bits;
out.string = malloc(bits);
if (out.string == NULL)
exit(-1);

for (i = bits; i >= 2; i--)
{

}

}
