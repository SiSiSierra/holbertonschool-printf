#include "main.h"

/**
 * reverse_string - reverse string in place
 *
 * @str: str to be reversed
 * @len: length of str
 */

void reverse_string(char *str, int len)
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
