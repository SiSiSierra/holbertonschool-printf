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
/* get int from arg list */
int n = va_arg(args, int);

int i = 0;
int tmp = n;
int len = 0;
char *buffer;
int start = 0, end = 0;
char swap;

/* handle zero case*/
if (n == 0)
{
buffer = malloc(2);

if (!buffer) 
return NULL;

buffer[0] = '0';
buffer[1] = '\0';

return buffer;
}

/* find len of number */
while (tmp > 0)
{
tmp /= 10;
len++;
}

/* allocate mem for buffer */
buffer = malloc(len + 1);
if (!buffer) 
return NULL;

/* add number in reverse */
tmp = abs(n);
for (i = 0; tmp > 0; i++)
{
buffer[i] = (tmp % 10) + '0';
tmp /= 10;
}

/* add negative sign*/
if (n < 0)
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

char *convert_str(va_list args)
{
	(void)args;

	return ("Tried to convert an str");
}
