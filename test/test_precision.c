#include "../main.h"
#include <stdio.h>

int main(void)
{
	printf("[%.*s]\n", 2, "Hello");
	_printf("[%.*s]\n", 2, "Hello");
	printf("[%08.5d]\n", 1);
	_printf("[%08.5d]\n", 1);
	printf("%.0s", "H!!\n");
	_printf("%.0s", "Hi!\n");


	return (0);
}
