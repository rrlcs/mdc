#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd, count, i, j, flag;
	char buff, arr[100];
	fd=open("/home/ravi/hello.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("Error in opening file");
		goto  OUT;
	}
	printf("sucess to open the file fd : %d\n",fd);
	
	flag=i = 0;

	while(count != 0)
	{
		count = read(fd,&buff,1);
		if(buff == 10)
		break;
		
		for(j=0; j<i; j++)
		{
			if(buff == arr[j])
			{
			flag = 1;
			break;
			}
		}
		
		if(flag == 0)
		{
			arr[i]=buff;
			i++;
		}
		flag = 0;
	
	}
	
		printf("data in the buff file is: %d\n", i);
//		arr[i]='\0';
		printf("master unique array :%s\n",arr);
		close(fd);

	return 0;

OUT :	return -1;
}
