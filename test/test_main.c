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

    x = -1234;
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

    
    printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    printf("%c", '\0');
    _printf("%c", '\0');
    printf("%!\n");
    _printf("%!\n");
    printf("%K\n");
    _printf("%K\n");

    printf("Length of lone percent char print: %d\n", printf("%"));
    _printf("Length of lone percent char print: %d\n", _printf("%"));

    printf("Length of terminating char print: %d\n", printf("%c", '\0'));
    _printf("Length of terminating char print: %d\n", _printf("%c", '\0'));

   _printf("binary of 0: %b\n", 0);
    _printf("binary of 35: %b\n", 35);
    _printf("binary of 35: %b\n", 5325);


_printf("oct test: %o\n", 0);           
_printf("oct test: %o\n", 1);           
_printf("oct test: %o\n", 10);        
_printf("oct test: %o\n", 123);       
_printf("oct test: %o\n", 1000);    
_printf("oct test: %o\n", 65535);   
_printf("oct test: %o\n", 1000000); 
_printf("oct test: %o\n", -1);   
_printf("oct test: %o\n", -2);

_printf("unsigned test: %u\n", 0);           
_printf("unsigned test: %u\n", 1);           
_printf("unsigned test: %u\n", 10);        
_printf("unsigned test: %u\n", 123);       
_printf("unsigned test: %u\n", 1000);    
_printf("unsigned test: %u\n", 65535);   
_printf("unsigned test: %u\n", 1000000); 
_printf("unsigned test: %u\n", -1);   
_printf("unsigned test: %u\n", -2);

    return (0);
}
