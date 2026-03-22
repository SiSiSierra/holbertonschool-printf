#include "../main.h"
#include <stdio.h>

int main(void)
{
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
