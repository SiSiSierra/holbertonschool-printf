#ifndef MAIN
#define MAIN

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/** Structures */

/**
 * struct flags - Contains boolean states for each accepted flag
 *
 * @hash: '#' flag is present
 * @zero: '0' flag is present
 * @hyphen: '-' flag is present
 * @space: ' ' flag is present
 * @plus: '+' flag is present
 *
 * Boolean means if the value is 0, it is false, and any other number is true.
 */
typedef struct flags
{
	char hash;
	char zero;
	char hyphen;
	char space;
	char plus;
} flags_t;

/**
 * struct format - Contains extracted fields from format substring
 *
 * @flags: List of all accepted flags as flag_t
 * @width: Non-zero positive number for minimum field width
 * @precision: Non-zero positive number for precision
 * @length: Determined length of total format substring
 */
typedef struct format
{
	flags_t flags;
	unsigned int width;
	unsigned int precision;
	unsigned int length;
} format_t;

/**
 * struct conversion - Group conversion specifier and function
 *
 * @specifier: Last character in format specifying data type
 * @f: Function associated with data type
 */
typedef struct conversion
{
        char specifier;
        char *(*f)(va_list, format_t);
} convert_t;

/** Main function, _printf */
int _printf(const char *format, ...);

/** Sub-functions */
char *get_conv_func(const char *, va_list, format_t);
format_t get_subformat(const char *);

char *convert_int(va_list, format_t);
char *convert_char(va_list, format_t);
char *convert_str(va_list, format_t);

char *convert_undefined(const char *, unsigned int);

/** Helper functions */
void reverse_string(char *buffer, int len);

#endif
