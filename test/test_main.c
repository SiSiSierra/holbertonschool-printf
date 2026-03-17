#include "../main.h"
#include <stdio.h>  

/*
compile - gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format _printf.c convert_and_format.c convert_numbers.c test/test_main.c -o test/test_printf
run file - ./test/test_printf
*/

int main(void)
{
	int len1 = 0;
	int len2 = 0;
	int x = -123;

	printf("Standard printf:\n");
	len1 = printf("test %d", x);
	printf("\n");
	printf("Our printf:\n");
	len2 = _printf("test %d", x);
	printf("\n");

	printf("Standard printf length: %d\n", len1);
	printf("Our printf length: %d\n", len2);	

	return (0);
}
