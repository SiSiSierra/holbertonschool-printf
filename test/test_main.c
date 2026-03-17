#include "../main.h"
#include <stdio.h> 
#include <limits.h>

/*
compile - gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c test/test_main.c -o test/test_printf
run file - ./test/test_printf
*/

int main(void)
{
	int len1 = 0;
    int len2 = 0;
    int x;

    /* Test negative integer */
    x = -123;
    printf("Standard printf:\n");
    len1 = printf("test %d\n", x);
    printf("Our printf:\n");
    len2 = _printf("test %d\n", x);
    printf("Standard printf length: %d\n", len1);
    printf("Our printf length: %d\n\n", len2);

    /* Test positive integer */
    x = 456;
    len1 = printf("test %d\n", x);
    len2 = _printf("test %d\n", x);
    printf("Standard printf length: %d\n", len1);
    printf("Our printf length: %d\n\n", len2);

    /* Test zero */
    x = 0;
    len1 = printf("zero: %d\n", x);
    len2 = _printf("zero: %d\n", x);
    printf("Standard printf length: %d\n", len1);
    printf("Our printf length: %d\n\n", len2);

    /* Test INT_MAX */
    x = INT_MAX;
    len1 = printf("INT_MAX: %d\n", x);
    len2 = _printf("INT_MAX: %d\n", x);
    printf("Standard printf length: %d\n", len1);
    printf("Our printf length: %d\n\n", len2);

    /* Test INT_MIN */
    x = INT_MIN;
    len1 = printf("INT_MIN: %d\n", x);
    len2 = _printf("INT_MIN: %d\n", x);
    printf("Standard printf length: %d\n", len1);
    printf("Our printf length: %d\n\n", len2);

    /* Escaped percent */
    len1 = printf("Percent sign: %%\n");
    len2 = _printf("Percent sign: %%\n");
    printf("Standard printf length: %d\n", len1);
    printf("Our printf length: %d\n\n", len2);	
    

    printf("Number -> %d <- Number\n", 5);
	_printf("Number -> %d <- Number\n", 5);
	printf("Number -> %d <- Number\n", 0);
    _printf("Number -> %d <- Number\n", 0);
	printf("Number -> %d <- Number\n", -5);
    _printf("Number -> %d <- Number\n", -5);
	printf("Number -> %d <- Number\n", 555995);
    _printf("Number -> %d <- Number\n", 555995);
	return (0);
}
