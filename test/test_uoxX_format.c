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

_printf("octal: %.0o\n", 0);
printf("octal: %.0o\n", 0);
_printf("octal: %#.0o\n", 0);
printf("octal: %#.0o\n", 0);

_printf("octal: %5.0o\n", 0);
printf("octal: %5.0o\n", 0);
_printf("octal: %#5.0o\n", 0);
printf("octal: %#5.0o\n", 0);

_printf("octal: %o\n", -1);
printf("octal: %o\n", -1);
_printf("octal: %#o\n", -1);
printf("octal: %#o\n", -1);

_printf("========== basic unsigned ==========\n");
_printf("unsigned: %u\n", 1234);
printf("unsigned: %u\n", 1234);
_printf("unsigned: %u\n", 0);
printf("unsigned: %u\n", 0);
_printf("unsigned: %u\n", UINT_MAX);
printf("unsigned: %u\n", UINT_MAX);
_printf("\n");

_printf("========== width ==========\n");
_printf("unsigned: %8u\n", 1234);
printf("unsigned: %8u\n", 1234);
_printf("unsigned: %-8u\n", 1234);
printf("unsigned: %-8u\n", 1234);
_printf("unsigned: %3u\n", 1234);
printf("unsigned: %3u\n", 1234);
_printf("\n");

_printf("========== precision ==========\n");
_printf("unsigned: %.6u\n", 1234);
printf("unsigned: %.6u\n", 1234);
_printf("unsigned: %.2u\n", 1234);
printf("unsigned: %.2u\n", 1234);
_printf("unsigned: %.0u\n", 0);
printf("unsigned: %.0u\n", 0);
_printf("\n");

_printf("========== width + precision ==========\n");
_printf("unsigned: %8.6u\n", 1234);
printf("unsigned: %8.6u\n", 1234);
_printf("unsigned: %-8.6u\n", 1234);
printf("unsigned: %-8.6u\n", 1234);
_printf("\n");

_printf("========== 0 flag ==========\n");
_printf("unsigned: %08u\n", 1234);
printf("unsigned: %08u\n", 1234);
_printf("unsigned: %-08u\n", 1234);
printf("unsigned: %-08u\n", 1234);
_printf("\n");

_printf("========== basic hex ==========\n");
_printf("hex: %x\n", 1234);
printf("hex: %x\n", 1234);
_printf("hex: %x\n", 0);
printf("hex: %x\n", 0);
_printf("hex: %x\n", UINT_MAX);
printf("hex: %x\n", UINT_MAX);
_printf("\n");

_printf("========== width ==========\n");
_printf("hex: %8x\n", 1234);
printf("hex: %8x\n", 1234);
_printf("hex: %-8x\n", 1234);
printf("hex: %-8x\n", 1234);
_printf("hex: %3x\n", 1234);
printf("hex: %3x\n", 1234);
_printf("\n");

_printf("========== precision ==========\n");
_printf("hex: %.6x\n", 1234);
printf("hex: %.6x\n", 1234);
_printf("hex: %.2x\n", 1234);
printf("hex: %.2x\n", 1234);
_printf("hex: %.0x\n", 0);
printf("hex: %.0x\n", 0);
_printf("\n");

_printf("========== # flag ==========\n");
_printf("hex: %#x\n", 1234);
printf("hex: %#x\n", 1234);
_printf("hex: %#x\n", 0);
printf("hex: %#x\n", 0);
_printf("hex: %#.6x\n", 1234);
printf("hex: %#.6x\n", 1234);
_printf("\n");

_printf("========== width + precision ==========\n");
_printf("hex: %8.6x\n", 1234);
printf("hex: %8.6x\n", 1234);
_printf("hex: %-8.6x\n", 1234);
printf("hex: %-8.6x\n", 1234);
_printf("\n");

_printf("========== 0 flag ==========\n");
_printf("hex: %08x\n", 1234);
printf("hex: %08x\n", 1234);
_printf("hex: %-08x\n", 1234);
printf("hex: %-08x\n", 1234);
_printf("\n");

_printf("========== basic HEX ==========\n");
_printf("HEX: %X\n", 1234);
printf("HEX: %X\n", 1234);
_printf("HEX: %X\n", 0);
printf("HEX: %X\n", 0);
_printf("HEX: %X\n", UINT_MAX);
printf("HEX: %X\n", UINT_MAX);
_printf("\n");

_printf("========== width ==========\n");
_printf("HEX: %8X\n", 1234);
printf("HEX: %8X\n", 1234);
_printf("HEX: %-8X\n", 1234);
printf("HEX: %-8X\n", 1234);
_printf("HEX: %3X\n", 1234);
printf("HEX: %3X\n", 1234);
_printf("\n");

_printf("========== precision ==========\n");
_printf("HEX: %.6X\n", 1234);
printf("HEX: %.6X\n", 1234);
_printf("HEX: %.2X\n", 1234);
printf("HEX: %.2X\n", 1234);
_printf("HEX: %.0X\n", 0);
printf("HEX: %.0X\n", 0);
_printf("\n");

_printf("========== # flag ==========\n");
_printf("HEX: %#X\n", 1234);
printf("HEX: %#X\n", 1234);
_printf("HEX: %#X\n", 0);
printf("HEX: %#X\n", 0);
_printf("HEX: %#.6X\n", 1234);
printf("HEX: %#.6X\n", 1234);
_printf("\n");

_printf("========== width + precision ==========\n");
_printf("HEX: %8.6X\n", 1234);
printf("HEX: %8.6X\n", 1234);
_printf("HEX: %-8.6X\n", 1234);
printf("HEX: %-8.6X\n", 1234);
_printf("\n");

_printf("========== 0 flag ==========\n");
_printf("HEX: %08X\n", 1234);
printf("HEX: %08X\n", 1234);
_printf("HEX: %-08X\n", 1234);
printf("HEX: %-08X\n", 1234);
_printf("\n");

_printf("========== edge cases ==========\n");
_printf("unsigned: %.0u\n", 0);
printf("unsigned: %.0u\n", 0);
_printf("hex: %.0x\n", 0);
printf("hex: %.0x\n", 0);
_printf("HEX: %.0X\n", 0);
printf("HEX: %.0X\n", 0);

_printf("unsigned: %u\n", UINT_MAX);
printf("unsigned: %u\n", UINT_MAX);
_printf("hex: %x\n", UINT_MAX);
printf("hex: %x\n", UINT_MAX);
_printf("HEX: %X\n", UINT_MAX);
printf("HEX: %X\n", UINT_MAX);

_printf("========== failed cases ==========\n");
_printf("hex: %#x\n", 0);
printf("hex: %#x\n", 0);
_printf("% \n"); 
printf("% \n"); 
_printf("% % % % \n");
printf("% % % % \n");
_printf("%.*d\n", 6, 102498402);
printf("%.*d\n", 6, 102498402);

_printf("\n");
}
