#include"header.h"
#include"prototypes.h"

int decompress()
{
	printf("In Function %s\n", __func__);
	int cl, len, fd, ret, pos;
	char ch, c;
	fd = open("masterArray", O_RDONLY);
	len = lseek(fd, 0, SEEK_END);
	printf("len  = %d", len);
	cl = code_length(len);	
	pos = lseek(fd, 0, SEEK_SET);
	printf("Code Length = %d", cl);
	printf("Position = %d", pos);

	switch(cl) {
		case 2 : 
			ret = decompress2(fd, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 3 : 
			ret = decompress3(fd, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 4 : 
			ret = decompress4(fd, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 5 : 
			ret = decompress5(fd, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 6 : 
			ret = decompress6(fd, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 7 : 
			ret = decompress7(fd, len);
			if(ret<0)
				perror("Error:\n");
			break;
	}
	
	return 0;
}
