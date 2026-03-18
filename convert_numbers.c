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
int n = va_arg(args, int); /* get int from arg list */
long i = 0, tmp = n, num = n;
int len = 0, negative = 0;
strout_t out;
(void) format;
if (n == 0) /* handle zero case*/
return (handle_zero_case());

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

/**
 * convert_num_to_base_8 - convert base 10 to base 8 and return as a string
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_num_to_base_8 (va_list args, format_t format)
{
char specifier = 'o';
unsigned int n = va_arg(args, unsigned int);
(void) format;
return (convert_num_to_base(n, specifier));
}

/**
 * convert_num_to_base - Convert an int into a string
 * @n: int from arg list
 * @specifier: format specifier
 * Return: Pointer to converted string
 */

strout_t convert_num_to_base (unsigned int n, char specifier)
{
unsigned int tmp = n;
unsigned int len = 0;
int i = 0;

unsigned int base = 0;
/* unsigned int uppercase = 0; */

strout_t out;

if (n == 0) /* handle 0 case */
return (handle_zero_case());

if (specifier == 'u') base = 10;
else if (specifier == 'o') base = 8;
else if (specifier == 'x') base = 16;
else
{
base = 16;
/* uppercase = 1; */
}

/* find len depending on base */
while (tmp > 0)
{
tmp /= base;
len++;
}

out.length = len;
out.string = malloc(len);
if (out.string == NULL)
exit(-1);

/* logic here */
/* start from */
for (i = len - 1; i >= 0 ;i--)
{
tmp = n % 8;
out.string[i] = tmp + '0';
n /= 8;
}

return (out);
}
