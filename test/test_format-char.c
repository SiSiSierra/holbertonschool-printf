#include "../main.h"
#include <stdio.h>

int main(void)
{
	printf("%s\n", "I am a string!");
	_printf("%s\n", "I am a string!");
	printf("5 letter A's -> %c%c%c%c%c\n", 'A', 'A', 'A', 'A', 'A');
	_printf("5 letter A's -> %c%c%c%c%c\n", 'A', 'A', 'A', 'A', 'A');

	return (0);
}
