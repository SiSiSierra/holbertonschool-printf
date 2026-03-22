#include "../main.h"
#include <stdio.h>

int main(void)
{
	printf("%s\n", "I am a string!");
	_printf("%s\n", "I am a string!");
	printf("5 letters -> %c%c%c%c%c\n", 'A', 'c', 'L', 'A', 'A');
	_printf("5 letters -> %c%c%c%c%c\n", 'A', 'c', 'L', 'A', 'A');

	return (0);
}
