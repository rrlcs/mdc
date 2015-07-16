#include"header.h"
#include"prototypes.h"

int decompress4(int fd, int len)
{
	printf("In Function %s\nfd = %d\n", __func__, fd);
	int cl, ekey, i, integer, dfd, count;
	unsigned char ch, c, buff, *ma, *dchar;
	ma = (char *) malloc(sizeof(char)*len);
	dchar = (char *) malloc(sizeof(char));
	ekey = open("encrypt", O_RDONLY);
	dfd = open("decompressed_file", O_WRONLY | O_CREAT | O_APPEND);
	i = 0;
	while(1)
	{
		read(fd, &ch, 1);
		
		if(ch == 10)
		{
			break;
		}
	
		*(ma+i) = ch;
		i++;
		
	}
	printf("Master Array in Decompress4.c is \n %s\n", ma);	
	while(1)
	{
	read(ekey, &buff, 1);
       	if(buff == 10)
	{
		break;
	}
	c = buff;
	c = c >> 4;
	integer = (int)c;
	printf("\nInteger Value = %d", integer);
		for(i=0; i<=len; i++)
		{
			if(integer == i)
			{
				*dchar = *(ma + i);

				write(dfd, dchar, 1);
			}
		}
	
	c = buff;
	c = c & 15;
	integer = (int)c;

	printf("\nInteger Value Second Time= %d", integer);

		for(i=0; i<=len; i++)
		{
			if(integer == i)
			{
				*dchar = *(ma + i);
				write(dfd, dchar, 1);
			}
		}
	}
	return 0;
}
