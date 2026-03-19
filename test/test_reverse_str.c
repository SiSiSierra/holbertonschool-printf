#include "../main.h"
#include <stdio.h> 
#include <limits.h>

/*
compile - 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c test/test_reverse_str.c -o test/test_printf
run file - 
./test/test_printf
*/

int main(void)
{
_printf("reverse %r\n", "dog");
_printf("reverse %r\n", "hello");
_printf("reverse %r\n", "why are there so many tasks");
_printf("reverse %r\n", "I think this works");
_printf("reverse %r\n", "");
_printf("reverse %r\n", "a");
_printf("reverse %r\n", "ab");
_printf("reverse %r\n", "four");
_printf("reverse %r\n", "aabbcc");
_printf("reverse %r\n", "a @ b ! c");
_printf("reverse %r\n", NULL);

return (0);
}

