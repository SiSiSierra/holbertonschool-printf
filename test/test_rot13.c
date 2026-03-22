#include "../main.h"

int main(void)
{
	_printf("%R", "the quick brown fox jumps over the lazy dog, ;-)\n");
	_printf("%R", "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG, ;-)\n");
	_printf("%R", "The QuIck Brown Fox Jumps $%^&Over the LAzy !!!DOg!!!, ;-)\n");
	return (0);
}
