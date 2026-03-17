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
str[start] = str[end];
str[end] = swap;
start++;
end--;
}
}
