#include "main.h"

/**
 * specifier_p_func - return memory address in string format
 *
 * @args: va_list arguments passed into print function
 * @format: Struct containing formatting arguments
 * Return: Pointer to converted string
 */

strout_t specifier_p_func(va_list args, format_t format)
{
void *ptr = va_arg(args, void*);
unsigned long address = (unsigned long)ptr;
strout_t out, hex = convert_num_to_base(address, 'x');
unsigned int i = 0;
(void) format;

if (ptr == NULL)
{
return (malloc_cpy_str("(nil)"));
}

/* allocate memory */
out.length = hex.length + 2;
out.string = malloc(out.length);

/* add 0x */
out.string[0] = '0';
out.string[1] = 'x';

/* copy hex to output */
while (i < hex.length)
{
out.string[2 + i] = hex.string[i];
i++;
}

free(hex.string);
return (out);
}
