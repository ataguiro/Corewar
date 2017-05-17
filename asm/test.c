#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	short n = 0xcafe;

	n = ((n >> 8) & 0xff) | ((n & 0xff) << 8);
	printf("%hx\n", n);
}
