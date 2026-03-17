#include "main.h"

/**
 * convert_int - Convert an int into a string
 *
 * @args: va_list with desired int next in line
 * Return: Pointer to converted string
 */

char *convert_int(va_list args)
{
int n = va_arg(args, int); /* get int from arg list */
long i = 0, tmp = n, num = n;
int len = 0, negative = 0;
char *buffer;
if (n == 0) /* handle zero case*/
{
buffer = malloc(2);
if (!buffer)
return (NULL);
buffer[0] = '0';
buffer[1] = '\0';
return (buffer);
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
buffer = malloc(len + negative + 1); /* allocate mem for buffer */
if (!buffer)
return (NULL);
for (i = 0; num > 0; i++) /* add number in reverse */
{
buffer[i] = (num % 10) + '0';
num /= 10;
}
if (negative == 1) /* add negative sign*/
buffer[i++] = '-';
reverse_string(buffer, i); /* reverse str in place */
buffer[i] = '\0';
return (buffer);
}
