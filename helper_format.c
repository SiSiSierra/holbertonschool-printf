#include "main.h"

/**
 * convert_format_unsigned_to_base - call functions to convert and format
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * @specifier: specifier
 * Return: strout struct with buffer and larger of width or len
 */
 
strout_t convert_format_unsigned_to_base(va_list args, format_t format, char specifier)
{
unsigned int data = va_arg(args, unsigned int);
strout_t out, tmp, base_str;

/* convert string to base */
base_str = convert_num_to_base(data, specifier);
/* apply precision format */
tmp = apply_precision(base_str, format);
/* apply # flag if needed */
if (specifier == 'x' || specifier == 'X')
tmp = apply_alternate_xX(tmp, format, specifier, data);
else if (specifier == 'o')
tmp = apply_alternate(tmp, format);

/* allocate memory using get buffer, handle width */
out = get_buffer(format.width, tmp.length);
/* pad out depending on width */
pad_buffer(out.string, tmp.length, format);
/* apply left flag */
out = apply_left(out, tmp, format);

free(tmp.string);
return (out);
}

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

/* if not specified */
if (format.precision < 0)
return base_str;

/* edge case */
if (format.precision == 0 && base_str.string[0] == '0' && base_str.length == 1)
{
tmp.string = malloc(0);
if (tmp.string == NULL)
exit(-1);
tmp.length = 0;
return (tmp);
}

/* apply precision */
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

/**
 * apply_alternate - apply alternate # flag to string
 *
 * @base_str: converted string without format
 * @format: Struct containing formatting arguments
 * Return: strout struct with buffer and larger of width or len
 */
strout_t apply_alternate(strout_t tmp, format_t format)
{
unsigned int i = 0;
strout_t tmp2;

if (format.flags.alternate && tmp.string[0] != '0')
{
tmp2.length = tmp.length + 1;
tmp2.string = malloc(tmp2.length);
if (tmp2.string == NULL)
exit(-1);

tmp2.string[0] = '0';
for (i = 0; i < tmp.length; i++)
tmp2.string[1 + i] = tmp.string[i];

free (tmp.string);
tmp = tmp2;
}

return (tmp);
}

/**
 * apply_alternate_xX - apply alternate # flag to hex string
 *
 * @base_str: converted string without format
 * @format: Struct containing formatting arguments
 * @specifier: specifier
 * Return: strout struct with buffer and larger of width or len
 */
strout_t apply_alternate_xX(strout_t tmp, format_t format, char specifier, unsigned int data)
{
unsigned int i = 0;
strout_t tmp2;

/* prepend for hex if alt flag true and data is not 0 */
if (format.flags.alternate && data != 0)
{
tmp2.length = tmp.length + 2;
tmp2.string = malloc(tmp2.length);
if (tmp2.string == NULL)
exit(-1);

tmp2.string[0] = '0';
tmp2.string[1] = specifier;
for (i = 0; i < tmp.length; i++)
tmp2.string[2 + i] = tmp.string[i];

free (tmp.string);
tmp = tmp2;
}

return (tmp);
}

/**
 * apply_left - apply left - flag to string
 *
 * @base_str: converted string without format
 * @format: Struct containing formatting arguments
 * Return: strout struct with buffer and larger of width or len
 */
strout_t apply_left(strout_t out, strout_t tmp, format_t format)
{
unsigned int i = 0, offset = 0;

if (!format.flags.left)
offset = out.length - tmp.length;

for (i = 0; i < tmp.length; i++)
out.string[i + offset] = tmp.string[i];

return (out);
}
