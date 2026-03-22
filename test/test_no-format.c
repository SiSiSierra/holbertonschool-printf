#include "../main.h"
#include <stdio.h>

int main(void)
{
	printf("Hello World!\n");
	_printf("Hello World!\n");

	printf("%d\n", printf("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$^&*()\n"));
	printf("%d\n", _printf("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$^&*()\n"));

	printf("%d\n", printf("%%%%Hi%%%%%%\n"));
	printf("%d\n", _printf("%%%%Hi%%%%%%\n"));

	return (0);
}
