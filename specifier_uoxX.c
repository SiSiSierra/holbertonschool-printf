#include "main.h"

/**
 * convert_unsigned_to_base_8 - convert unsigned in to base 8
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_8(va_list args, format_t format) {
    return convert_format_unsigned_to_base(args, format, 'o');
}
/**
 * convert_unsigned_to_base_10 - convert unsigned to base 10
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_10(va_list args, format_t format) {
    return convert_format_unsigned_to_base(args, format, 'u');
}

/**
 * convert_unsigned_to_base_16 - convert unsigned to base 16
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_16(va_list args, format_t format) {
    return convert_format_unsigned_to_base(args, format, 'x');
}


/**
 * convert_unsigned_to_base_16_X - convert unsigned int to base 16 upper
 *
 * @args: va_list with desired int next in line
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t convert_unsigned_to_base_16_X(va_list args, format_t format) {
    return convert_format_unsigned_to_base(args, format, 'X');
}
