#include "main.h"

/**
 * apply_precision - apply precision format to string
 *
 * @base_str: converted string without format
 * @format: Struct containing formatting arguments
 * Return: strout struct with buffer and larger of width or len
 */
strout_t apply_precision(strout_t base_str, format_t format)
{
unsigned int i = 0, prefix_len = 0;
strout_t tmp;

if (format.precision < 0)
return base_str;

if (base_str.length < (unsigned int)format.precision)
{
prefix_len = format.precision - base_str.length;
tmp.string = malloc(prefix_len + base_str.length);
if (tmp.string == NULL)
exit(-1);
/* prepend zeros */
for (i = 0; i < prefix_len; i++)
tmp.string[i] = '0';
/* copy base str to out.string */
for (i = 0; i < base_str.length; i++)
tmp.string[prefix_len + i] = base_str.string[i];

tmp.length = base_str.length + prefix_len;
free(base_str.string);
return (tmp);
}

return (base_str);
}
