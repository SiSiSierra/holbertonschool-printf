#include "main.h"

/**
 * print_non_printable - return string including unprintable
 *
 * @args: va_list arguments passed into print function
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t print_non_printable(va_list args, format_t format)
{
char *data = va_arg(args, char *);
strout_t out, hex;
unsigned int i = 0, j = 0, k = 0, len = 0;
unsigned char c = 0;
(void) format;
if (data == NULL)
data = "(null)";
while (data[i] != '\0') /* first loop to get len */
{
c = data[i];
if (c < 32 || c >= 127)
len += 4;
else
len += 1;
i++;
}
out.length = len;
out.string = malloc(len);
if (out.string == NULL)
exit(-1);
i = 0;
while (data[i] != '\0') /* second loop to construct string */
{
c = data[i];
if (c < 32 || c >= 127)
{
hex = convert_num_to_base(c, 'X');
out.string[j++] = '\\';
out.string[j++] = 'x';
if (hex.length == 1)
out.string[j++] = '0';
for (k = 0; k < hex.length; k++) /* copy hex value to string */
out.string[j++] = hex.string[k];
free(hex.string);
}
else
out.string[j++] = data[i];
i++;
}
return (out);
}

