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
unsigned int n = va_arg(args, unsigned int);
(void) format;
return (convert_num_to_base(n, specifier));
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
