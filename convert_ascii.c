#include "main.h"

/**
 * convert_ - Return attempted format substring
 *
 * @substring: Pointer to substring
 * @len: Length of substring
 * Return: Undefined format substring
 */

strout_t print_non_printable(va_list args, format_t format)
{
// grab arg
char *data = va_arg(args, char *);
strout_t out;
strout_t hex;
int i = 0, j = 0, k = 0;
unsigned char a = 0, len = 0;
(void) format;

if (data == NULL)
data = "(null)";

/* first loop to get len */
while (data[i] != '\0')
{
a = data[i];
if (a < 32 || a >= 127)
len += 4;
else
len += 1;

i++;
}

/* allocate memory */
out.string = malloc(len);
if (out.string == NULL)
exit(-1);

/* second loop to construct string */
while(j < len)
{
a = data[j];

if (a < 32 || a >= 127)
{
hex = convert_unsigned_to_base_16_X(a)

out.string[j] = '\\';
out.string[j + 1] = 'x';

if (hex.length == 1)
out.string[j + 2] = '0';

for (k = 0; k < hex.length; k++)
out.string[j + 3 + k] = hex.string[k];

j += 4;
}
else
{
out.string[j] = data[i];
j++;
}
}


return (out);
}

