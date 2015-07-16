#include"header.h"
#include"prototypes.h"

int decompress5(int fd, int len)
{
	int cl, ekey, i;
	char ch, *c, buff, ma;
	ekey = open("encrypt", O_RDONLY);
//	fd = open("masterArray", O_RDONLY);
	read(ekey, &buff, 1);
       	*c = buff;
	*c = *c >> 4;
	i = atoi(c);
	while(1)
	{
		read(fd, &ma, 1);
		if(!ma)
		{
			break;
		}
		if(i == ma)
		{
			
		}
	}
	return 0;
}
