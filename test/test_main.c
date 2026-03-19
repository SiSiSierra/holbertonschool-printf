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

    


	_printf("Flag recognition\n");
	len1 = printf("%d\n", 500);
	len2 = _printf("%0+d\n", 500);
	printf("^ normal = %d, ours = %d\n", len1, len2);
	len1 = printf("%s | Thing with flags -> %s", "Hello", "Hi\n");
	len2 = _printf("%s | Thing with flags -> %#0-## +1234289.234ls", "Hello", "Hi\n");
	printf("^ normal = %d, ours = %d\n", len1, len2);
	printf("printf Invalid flags -> %####@d\n", 50);
	_printf("_printf Invalid flags -> %####@d\n", 50);
	printf("printf Invalid flags -> %# +.+d\n", 50);
        _printf("_printf Invalid flags -> %# +.+d\n", 50);

    return (0);
}

