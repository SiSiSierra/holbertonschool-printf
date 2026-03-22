#include "../main.h"
#include <stdio.h> 
#include <limits.h>

/*
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c test/test_uoxX_format.c -o test/test_printf
./test/test_printf
*/

int main(void)
{
_printf("========== basic octal ==========\n");
_printf("octal: %o\n", 1234);
printf("octal: %o\n", 1234);
_printf("octal: %o\n", 0);
printf("octal: %o\n", 0);
_printf("\n");

_printf("========== width ==========\n");
_printf("octal: %8o\n", 1234);
printf("octal: %8o\n", 1234);
_printf("octal: %-8o\n", 1234);
printf("octal: %-8o\n", 1234);
_printf("octal: %3o\n", 1234); 
printf("octal: %3o\n", 1234); 
_printf("\n");

_printf("========== precision ==========\n");
_printf("octal: %.6o\n", 1234);
printf("octal: %.6o\n", 1234);
_printf("octal: %.4o\n", 1234);
printf("octal: %.4o\n", 1234);
_printf("octal: %.2o\n", 1234);
printf("octal: %.2o\n", 1234);
_printf("octal: %.0o\n", 0);
printf("octal: %.0o\n", 0);
_printf("octal: %.0o\n", 1234);
printf("octal: %.0o\n", 1234);
_printf("\n");

_printf("========== # flag ==========\n");
_printf("octal: %#o\n", 1234);
printf("octal: %#o\n", 1234);
_printf("octal: %#o\n", 0); 
printf("octal: %#o\n", 0); 
_printf("octal: %#.6o\n", 1234);
printf("octal: %#.6o\n", 1234);
_printf("octal: %#.6o\n", 0);
printf("octal: %#.6o\n", 0);
_printf("\n");

_printf("========== width + precision ==========\n");
_printf("octal: %8.6o\n", 1234);
printf("octal: %8.6o\n", 1234);
_printf("octal: %-8.6o\n", 1234);
printf("octal: %-8.6o\n", 1234);
_printf("octal: %4.6o\n", 1234);
printf("octal: %4.6o\n", 1234);
_printf("\n");

_printf("========== # + width ==========\n");
_printf("octal: %#8o\n", 1234);
printf("octal: %#8o\n", 1234);
_printf("octal: %-#8o\n", 1234);
printf("octal: %-#8o\n", 1234);
_printf("\n");

_printf("========== # + precision ==========\n");
_printf("octal: %#.6o\n", 1234);
printf("octal: %#.6o\n", 1234);
_printf("octal: %#.3o\n", 1234);
printf("octal: %#.3o\n", 1234);
_printf("\n");

_printf("========== 0 flag ==========\n");
_printf("octal: %08o\n", 1234);
printf("octal: %08o\n", 1234);
_printf("octal: %-08o\n", 1234); 
printf("octal: %-08o\n", 1234); 
_printf("\n");

_printf("========== 0 + precision ==========\n");
_printf("octal: %08.6o\n", 1234); 
printf("octal: %08.6o\n", 1234); 
_printf("\n");

_printf("========== # + 0 ==========\n");
_printf("octal: %#08o\n", 1234);
printf("octal: %#08o\n", 1234);
_printf("\n");

_printf("========== left flag ==========\n");
_printf("octal: %-8.6o\n", 1234);
printf("octal: %-8.6o\n", 1234);
_printf("octal: %-#8o\n", 1234);
printf("octal: %-#8o\n", 1234);
_printf("\n");

_printf("========== edge cases ==========\n");

// zero with precision
_printf("octal: %.0o\n", 0);
printf("octal: %.0o\n", 0);
_printf("octal: %#.0o\n", 0);
printf("octal: %#.0o\n", 0);

// width + zero + precision
_printf("octal: %5.0o\n", 0);
printf("octal: %5.0o\n", 0);
_printf("octal: %#5.0o\n", 0);
printf("octal: %#5.0o\n", 0);

// large values
_printf("octal: %o\n", -1);
printf("octal: %o\n", -1);
_printf("octal: %#o\n", -1);
printf("octal: %#o\n", -1);

_printf("\n");
}
