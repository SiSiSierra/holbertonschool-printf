#include <stdio.h>
#include "../main.h"

int main(void)
{
	printf("[%010c]\n", 'I');
	_printf("[%010c]\n", 'I');
	printf("[%-010c]\n", 'I');
        _printf("[%-010c]\n", 'I');
        printf("[%0256c]\n", 'I');
        _printf("[%0256c]\n", 'I');
        printf("[%-0256c]\n", 'I');
        _printf("[%-0256c]\n", 'I');


	return (0);
}
