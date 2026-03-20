#include <stdio.h>
#include "../main.h"

int main(void)
{
	printf("[%010c]\n", 'I');
	_printf("[%010c]\n", 'I');
	printf("[%-010c]\n", 'I');
        _printf("[%-010c]\n", 'I');
        printf("[%025c]\n", 'I');
        _printf("[%025c]\n", 'I');
        printf("[%-025c]\n", 'I');
        _printf("[%-025c]\n", 'I');


	printf("[%010s]\n", "Eye");
        _printf("[%010s]\n", "Eye");
	printf("[%-010s]\n", "Eye");
        _printf("[%-010s]\n", "Eye");
	printf("[%0100s]\n", "Eye");
        _printf("[%0100s]\n", "Eye");
	printf("[%0-100s]\n", "Eye");
        _printf("[%0-100s]\n", "Eye");


	return (0);
}
