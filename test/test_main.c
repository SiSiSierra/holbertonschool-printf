#include "../main.h"
#include <stdio.h> 
#include <limits.h>

/*
compile - 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c test/test_main.c -o test/test_printf
run file - 
./test/test_printf
*/

int main(void)
{
_printf("========== int test ==========\n");
_printf("int printed: %i\n", 0);           
_printf("int printed: %i\n", 1);          
_printf("int printed: %i\n", -1);     
_printf("int printed: %i\n", 12345);  
_printf("int printed: %i\n", -12345);
_printf("INT_MAX printed: %i = 2147483647\n", INT_MAX); 
_printf("INT_MIN printed: %i = -2147483648\n", INT_MIN); 
_printf("\n");

_printf("========== binary test ==========\n");
_printf("binary printed: %b = 0\n", 0);
_printf("binary printed: %b = 1\n", 1);
_printf("binary printed: %b = 1010\n", 10);
_printf("binary printed: %b = 11111111\n", 255);
_printf("\n");

_printf("========== octal test ==========\n");
_printf("octal printed: %o = 0\n", 0);
_printf("octal printed: %o = 10\n", 8);
_printf("octal printed: %o = 377\n", 255);
_printf("octal printed: %o = 37777777777\n", -1);
_printf("UINT_MAX oct printed: %o = 37777777777\n", UINT_MAX);
_printf("\n");

_printf("========== unsigned test ==========\n");
_printf("unsigned printed: %u = 0\n", 0); 
_printf("unsigned printed: %u = 1\n", 1); 
_printf("unsigned printed: %u = 123\n", 123); 
_printf("unsigned printed: %u = 4294967295\n", -1); 
_printf("UINT_MAX unsigned printed: %u = 4294967295\n", UINT_MAX);
_printf("\n");

_printf("========== hex test ==========\n");
_printf("hex printed: %x = 0\n", 0); 
_printf("hex printed: %x = a\n", 10); 
_printf("hex printed: %x = f\n", 15); 
_printf("hex printed: %x = ff\n", 255);
_printf("hex printed: %x = ffffffff\n", -1);
_printf("UINT_MAX hex printed: %x = ffffffff\n", UINT_MAX);
_printf("\n");

_printf("========== HEX test ==========\n");
_printf("HEX printed: %X = 0\n", 0); 
_printf("HEX printed: %X = A\n", 10); 
_printf("HEX printed: %X = F\n", 15); 
_printf("HEX printed: %X = FF\n", 255);
_printf("HEX printed: %X = FFFFFFFF\n", -1);
_printf("UINT_MAX HEX printed: %X = FFFFFFFF\n", UINT_MAX);
_printf("\n");

return (0);
}

