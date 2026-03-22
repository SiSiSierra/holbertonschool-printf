#include "main.h"

/**
 * convert_unsigned_to_base_8 - convert unsigned in to base 8
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_8(va_list args, format_t format)
{
char specifier = 'o';
unsigned int data = va_arg(args, unsigned int), offset = 0;
strout_t base_str = convert_num_to_base(data, specifier);
strout_t out, tmp, tmp2;

unsigned int i = 0, prefix_len = 0;
/* apply precision */
/* check for out.length < precision */
/* if so, apply 0 to front of string */
if (base_str.length < (unsigned int)format.precision)
{
prefix_len = format.precision - base_str.length;
tmp.string = malloc(prefix_len + base_str.length);
/* prepend zeros */
for (i = 0; i < prefix_len; i++)
tmp.string[i] = '0';
/* copy base str to out.string */
for (i = 0; i < base_str.length; i++)
tmp.string[prefix_len + i] = base_str.string[i];

tmp.length = base_str.length + prefix_len;
free(base_str.string);
}
else
tmp = base_str;

/* apply # flag */
/* prepend 0 if value != 0 and first char isn't already 0 */
/* prepend zero */
if (format.flags.alternate && tmp.string[0] != '0')
{
tmp2.length = tmp.length + 1;
tmp2.string = malloc(tmp2.length);

tmp2.string[0] = '0';
for (i = 0; i < tmp.length; i++)
tmp2.string[1 + i] = tmp.string[i];

free (tmp.string);
tmp = tmp2;
}

/* allocate memory using get buffer, handle width */
out = get_buffer(format.width, tmp.length);
/* pad out depending on width */
pad_buffer(out.string, out.length, format);

/* flag left */
/* if left copy number after padding */
/* else copy padding starting i = 0 */

offset = out.length - tmp.length;
if (offset < 0)
offset = 0;
for (i = 0; i < tmp.length; i++)
out.string[i + offset] = tmp.string[i];

free(tmp.string);
return (out);
}

/**
 * convert_unsigned_to_base_10 - convert unsigned to base 10
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_10(va_list args, format_t format)
{
char specifier = 'u';
unsigned int n = va_arg(args, unsigned int);
(void) format;
return (convert_num_to_base(n, specifier));

}

/**
 * convert_unsigned_to_base_16 - convert unsigned to base 16
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_16(va_list args, format_t format)
{
char specifier = 'x';
unsigned int n = va_arg(args, unsigned int);
(void) format;
return (convert_num_to_base(n, specifier));
}

/**
 * convert_unsigned_to_base_16_X - convert unsigned int to base 16 upper
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_16_X(va_list args, format_t format)
{
char specifier = 'X';
unsigned int n = va_arg(args, unsigned int);
(void) format;
return (convert_num_to_base(n, specifier));
}
