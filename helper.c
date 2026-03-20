#include "main.h"

/**
 * reverse_string - reverse string in place
 *
 * @str: str to be reversed
 * @len: length of str
 */

void reverse_string_helper(char *str, int len)
{
long start = 0;
long end = len - 1;
char swap;

while (start < end)
{
swap = str[start];
str[start++] = str[end];
str[end--] = swap;
}
}

/**
 * handle_zero_case - handle when arg == 0
 *
 * Return: strout_t string as '0' and length as 1
 */

strout_t handle_zero_case(void)
{
strout_t out;

out.string = malloc(1);
if (out.string == NULL)
exit(-1);
out.string[0] = '0';
out.length = 1;

return (out);
}

/**
 * convert_num_to_base - Convert an int into a string
 * @n: int from arg list
 * @specifier: format specifier
 * Return: Pointer to converted string
 */

strout_t convert_num_to_base(unsigned int n, char specifier)
{
unsigned int tmp = n, len = 0, base = 0;
int i = 0;
char *nums = "0123456789abcdef";
strout_t out;

if (n == 0) /* handle 0 case */
return (handle_zero_case());

if (specifier == 'u')
base = 10;
else if (specifier == 'o')
base = 8;
else if (specifier == 'x')
base = 16;
else
{
base = 16;
nums = "0123456789ABCDEF";
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

/* fill string from least significant to most */
for (i = len - 1; i >= 0 ; i--)
{
out.string[i] = nums[n % base];
n /= base;
}

return (out);
}
