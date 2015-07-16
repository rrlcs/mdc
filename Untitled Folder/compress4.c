#include"header.h"
#include"prototypes.h"

int compress4(int fd, char* arr, int len)
{
	int i, j, l, index, ekey, pos;
	char buff;
	char b, c, byte;
	byte ^= byte;	
	pos  =	lseek(fd, 0, SEEK_SET);	
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
		c = c << 4;
		byte = byte | c;

		read(fd, &buff, 1);
		if(buff == 10)
		{
			break;
		}
                index = find_index(buff, arr, len);
		b = index;
		b = b << 4;
		b = b >> 4;
		byte = byte | b;
                ekey = open("encrypt", O_WRONLY | O_APPEND);
                write(ekey, &byte,  1);
		byte ^= byte; 
	}
	return 0;
}
