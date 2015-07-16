#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int code_length(int);		//Function for finding code length.
int open_file1();		//Function for reading file.
char* master_array(int);	//Function for creating unique master array.
int create_file2(char* , int);	//Function for writing to a new file.

//Starting Function MAIN.

int main()
{
	int fd, cl,len;
	char buff, *arr;

	arr = (char *) malloc(100*sizeof(char));
	fd = open_file1();

	arr = master_array(fd);	

	len = strlen(arr);

	create_file2(arr, len);	

	cl = code_length(len);

	return 0;

}

//function Definitions.

int open_file1()
{
	int fd = open("hello", O_RDONLY);
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
	arr = (char *) malloc(sizeof(char) * 100);

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
			*(arr+i)=buff;
			i++;
		}
		flag = 0;
	
	}
	
		printf("data in the buff file is: %d\n", i);
		arr[i]='\0';
		printf("master unique array :%s\n",arr);


		return(arr);
	
}

int create_file2(char *arr, int i)
{
	int efd;
	efd = open("GOT", O_WRONLY | O_CREAT);
	
	write(efd,arr,i);
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
