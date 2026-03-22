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
unsigned int data = va_arg(args, unsigned int);
strout_t out, tmp, base_str;

/* convert string to base */
base_str = convert_num_to_base(data, specifier);
/* apply precision format */
tmp = apply_precision(base_str, format);
/* apply # flag */
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
 * convert_unsigned_to_base_10 - convert unsigned to base 10
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_10(va_list args, format_t format)
{
char specifier = 'u';
unsigned int data = va_arg(args, unsigned int);
strout_t base_str, tmp, out;

/* convert string to base */
base_str = convert_num_to_base(data, specifier);
/* apply precision format */
tmp = apply_precision(base_str, format);
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
 * convert_unsigned_to_base_16 - convert unsigned to base 16
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_16(va_list args, format_t format)
{
char specifier = 'x';
unsigned int data = va_arg(args, unsigned int);
strout_t out, tmp, base_str;

/* convert string to base */
base_str = convert_num_to_base(data, specifier);
/* apply precision format */
tmp = apply_precision(base_str, format);
/* apply # flag */
tmp = apply_alternate_xX(tmp, format, specifier);
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
 * convert_unsigned_to_base_16_X - convert unsigned int to base 16 upper
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_16_X(va_list args, format_t format)
{
char specifier = 'X';
unsigned int data = va_arg(args, unsigned int);
strout_t out, tmp, base_str;

/* convert string to base */
base_str = convert_num_to_base(data, specifier);
/* apply precision format */
tmp = apply_precision(base_str, format);
/* apply # flag */
tmp = apply_alternate_xX(tmp, format, specifier);
/* allocate memory using get buffer, handle width */
out = get_buffer(format.width, tmp.length);
/* pad out depending on width */
pad_buffer(out.string, tmp.length, format);
/* apply left flag */
out = apply_left(out, tmp, format);

free(tmp.string);
return (out);
}
