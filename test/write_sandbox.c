#include <unistd.h>

int main()
{
	write(1, "Test\n12345", 7);
	write(1, "\n", 1);
	return (0);
}
