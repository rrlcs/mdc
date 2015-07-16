#include"header.h"
#include"prototypes.h"

int compress5(int fd, char * arr, int len)
{
	printf("IN Function %s\t", __func__);
	printf("len = %d", len);
	int i, j, l, index, ekey, pos;
        char buff;
        char b, c, copy, byte;
        byte ^= byte;
        pos  =  lseek(fd, 0, SEEK_SET);
        printf("\n Position = %d", pos);

	while(1)
	{
		read(fd, &buff, 1);
		if(buff == 10)
		{
			break;
		}
		index = find_index(buff, arr, len);
		printf("Index = %d\n", index);
		c = index;
		c = c << 3;
		byte = byte | c;
		read(fd, &buff, 1);
		if(buff == 10)
		{
			break;
		}
		index = find_index(buff, arr, len);
		b = index;
		b = b << 3;
		b = b >> 3;
		copy = b;
		b = b & 7;
		byte = byte | b;
		ekey = open("encrypt5", O_WRONLY | O_CREAT);
		write(ekey, &byte, 1);
		byte ^= byte;
	}
	return 0;
}
