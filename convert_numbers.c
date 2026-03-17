#include "main.h"

/**
 * convert_int - Convert an int into a string
 *
 * @args: va_list with desired int next in line
 * Return: Pointer to converted string
 */
char *convert_int(va_list args)
{
/* get int from arg list */
int n = va_arg(args, int);
long i = 0, tmp = n, start = 0, end = 0;
int len = 0, negative = 0;
char *buffer, swap;
/* handle zero case*/
if (n == 0)
{
buffer = malloc(2);
if (!buffer)
return (NULL);
buffer[0] = '0';
buffer[1] = '\0';
return (buffer);
}
/* convert tmp to positive and store sign */
if (tmp < 0)
{
tmp = -tmp;
negative = 1;
}
/* find len of number */
while (tmp > 0)
{
tmp /= 10;
len++;
}
/* reset tmp */
tmp = n;
if (negative == 1)
tmp = -tmp;
/* allocate mem for buffer */
buffer = malloc(len + negative + 1);
if (!buffer)
return (NULL);
/* add number in reverse */
for (i = 0; tmp > 0; i++)
{
buffer[i] = (tmp % 10) + '0';
tmp /= 10;
}
/* add negative sign*/
if (negative == 1)
buffer[i++] = '-';
/* reverse str in place */
start = 0;
end = i - 1;
while (start < end)
{
swap = buffer[start];
buffer[start] = buffer[end];
buffer[end] = swap;
start++;
end--;
}
return (buffer);
}
