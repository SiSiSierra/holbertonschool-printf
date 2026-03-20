#include <stdio.h>
#include "../main.h"

int main(void)
{
	_printf("Chars\n");
	printf("[%010c]\n", 'I');
	_printf("[%010c]\n", 'I');
	printf("[%-010c]\n", 'I');
        _printf("[%-010c]\n", 'I');
        printf("[%025c]\n", 'I');
        _printf("[%025c]\n", 'I');
        printf("[%-025c]\n", 'I');
        _printf("[%-025c]\n", 'I');


	_printf("Strings\n");
	printf("[%010s]\n", "Eye");
        _printf("[%010s]\n", "Eye");
	printf("[%-010s]\n", "Eye");
        _printf("[%-010s]\n", "Eye");
	printf("[%0100s]\n", "Eye");
        _printf("[%0100s]\n", "Eye");
	printf("[%0-100s]\n", "Eye");
        _printf("[%0-100s]\n", "Eye");

	_printf("Ints\n");
	printf("[%+010d]\n", 159);
	_printf("[%+010d]\n", 159);
	printf("[%015d]\n", -159);
	_printf("[%015d]\n", -159);
	printf("[%-07d]\n", 159);
        _printf("[%-07d]\n", 159);
        printf("[%-010d]\n", -159);
        _printf("[%-010d]\n", -159);


	return (0);
}
