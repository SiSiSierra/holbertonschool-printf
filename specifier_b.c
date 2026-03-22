#include "main.h"

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
