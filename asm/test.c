#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	long	test[5];
	int	fd = open("test.cor", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	test[0] = (char)0x25;
	test[1] = 0x4;
	test[2] = 0x55;
	test[3] = (short)0x25;
	test[4] = (char)0x50;
	for (int i = 0; i <= 4; i++)
		dprintf(fd, "%ls", &test[i]);
}
