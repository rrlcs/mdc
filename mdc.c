#include"header.h"
#include"prototypes.h"

int main()
{
	int fd, cl, efd, choice;
	char buff, *arr;

	fd = open_file1();
	arr = master_array(fd);
	while(1)
	{
		printf("____MAIN MENU____\n");
		printf("1 : Compression\n");
		printf("2 : Decompression\n");
		printf("0 : Exit\n");
		printf("Enter Your Choice : \t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : 
				compress(fd, arr);
				break;
			case 2 : 
				decompress();
				break;
			case 0 : 
				exit(EXIT_SUCCESS);
				break;
		}
	}
	return 0;

}

int open_file1(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}

	
	return fd;
}

char* master_array(int fd)
{
	int count, i, j, flag;
	char buff, *arr;
	arr = NULL;
	
	printf("sucess to open the file fd : %d\n",fd);
	
	flag=i = 0;

	count = 1;
	while(count != 0)
	{
		count = read(fd,&buff,1);
		if(buff == 10)
		break;
				
		for(j=0; j<i; j++)
		{
			if(buff == *(arr+j))
			{
			flag = 1;
			break;
			}
		}
		
		if(flag == 0)
		{
			
			arr = (char *) realloc(arr, i+1);
			*(arr+i)=buff;
			i++;
		}
		flag = 0;
	
	}
	
		printf("data in the buff file is: %d\n", i);
		arr[i]=0x0A;
		printf("master unique array :%s\n",arr);


		return(arr);
	
}

int create_file2(char *arr, int i)
{
	int efd;
	efd = open("masterArray", O_WRONLY | O_CREAT);
	
	write(efd,arr,i);
	return efd;
}

int code_length(int i)
{
	if(i < 4)
		return 2;
	else if(i < 8)
		return 3;
	else if(i < 16)
		return 4;
	else if(i < 32)
		return 5;
	else if(i < 64)
		return 6;
	else if(i < 128)
		return 7;
	else if(i < 256)
		return 8;
}
