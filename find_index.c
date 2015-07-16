#include"header.h"
#include"prototypes.h"

int find_index(char buff, char* arr, int len)
{
	int i =0;
	while(i<=len)
	{
		if(buff  == *(arr + i))
		{
			return i;
		}
		i++;
	}
	return -1;
}
