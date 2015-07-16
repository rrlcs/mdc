#include"header.h"
#include"prototypes.h"

compress(int fd, int efd)
{
	char *buff, *arr, *encrypted, ch, c, byte;
	int i, j, l1, l2, index, ekey;
	byte = byte ^ byte;
	buff = (char*)malloc(sizeof(char)*128);
	buff = (char*)malloc(sizeof(char)*128);
	buff = (char*)malloc(sizeof(char)*128);
	
//	open("hello", O_RDONLY);
//OB	open("GOT", O_RDONLY);
	
	read(fd, &buff, 50);
	l1 = strlen(buff);
	
	read(efd, &arr, 50);
	l2 = strlen(arr);

	while(buff = NULL)
	{
		for(i=1; i<=l1; i++)
		{
		ch = *(buff + i);
		for(j=1; j<=l2; j++)
		{
			if(j/2!=0)
			{
				if(ch == *(arr + j))
				{
					index = j;
					c = index;
					c << 4;
					byte = byte | c;
				}
			}
			else
			{
				
				if(ch == *(arr + j))
				{
					index = j;
					c = index;
					c << 4;
					c >> 4;
					byte = byte | c;
					ekey = open("encrypted", O_WRONLY | O_CREAT);
					write(ekey, encrypted,  1);
				}
			}
		}
		}
	}
	
}
