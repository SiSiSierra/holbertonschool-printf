#ifndef MAIN
#define MAIN

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/** Main function, _printf */
int _printf(const char *format, ...);

/** Sub-functions */
char *convert_and_format(const char *, va_list);
char *(*get_conv_func(const char *))(va_list);

char *convert_int(va_list);

/** Structures */

/**
 * struct conversion - Group conversion specifier and function
 *
 * @specifier: Last character in format specifying data type
 * @f: Function associated with data type
 */
typedef struct conversion
{
	char *specifier;
	char *(*f)(va_list args);
} convert_t;

#endif
