#include "../main.h"
#include <stdio.h>

int main(void)
{
	printf("[%.2s]\n", "Hello");
	_printf("[%.2s]\n", "Hello");
	printf("[%08.5d]\n", 1);
	_printf("[%08.5d]\n", 1);


	return (0);
}
