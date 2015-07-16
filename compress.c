#include"header.h"
#include"prototypes.h"

int compress(int fd, char* arr)
{
	int cl, len, efd, ret;

	len = strlen(arr);
	printf("len  = %d", len);
        
	cl = code_length(len);
	efd = create_file2(arr, len);
	
	printf("Code Length = %d", cl);

	switch(cl) {
		case 2 : 
			ret = compress2(fd, arr, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 3 : 
			ret = compress3(fd, arr, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 4 : 
			ret = compress4(fd, arr, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 5 : 
			ret = compress5(fd, arr, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 6 : 
			ret = compress6(fd, arr, len);
			if(ret<0)
				perror("Error:\n");
			break;
		case 7 : 
			ret = compress7(fd, arr, len);
			if(ret<0)
				perror("Error:\n");
			break;
	}
	
	return 0;
}
