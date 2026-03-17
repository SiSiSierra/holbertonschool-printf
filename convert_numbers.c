#include "main.h"

/**
 * convert_int - Convert an int into a string
 *
 * @args: va_list with desired int next in line
 * Return: Pointer to converted string
 */
char *convert_char(va_list args)
{
(void)args;

return ("Tried to convert an char");
}

char *convert_int(va_list args)
{
int n = va_arg(args, int); /* get int from arg list */
long i = 0, tmp = n, num = n, start = 0, end = 0;
int len = 0, negative = 0;
char *buffer, swap;
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
start = 0; /* reverse str in place */
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

char *convert_str(va_list args)
{
(void)args;

return ("Tried to convert an str");
}
