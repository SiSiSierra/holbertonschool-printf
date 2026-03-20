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
unsigned int i = 0, j = 0, k = 0;
unsigned char c = 0, len = 0;
(void) format;

if (data == NULL)
data = "(null)";

/* first loop to get len */
while (data[i] != '\0')
{
c = data[i];
if (c < 32 || c >= 127)
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
// data = original length
// len = including hex
i = 0;
while(data[i] != '\0')
{
c = data[i];

if (c < 32 || c >= 127)
{
hex = convert_num_to_base(c, 'X');

out.string[j++] = '\\';
out.string[j++] = 'x';

if (hex.length == 1)
out.string[j++] = '0';

for (k = 0; k < hex.length; k++)
out.string[j++] = hex.string[k];

free(hex.string);
}
else
{
out.string[j] = data[i];
}

i++;
}

return (out);
}

