#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void fillblack(char *arr)
{
	assert(arr);
	int len = strlen(arr);
	int blacks = 0;
	char *oldEnd = arr + len;
	char *newEnd = arr + len ;
	while (*arr++)
	{
		if (*arr == ' ')
			blacks++;
		
	}
	newEnd += 2 * blacks;
	while (oldEnd <= newEnd)
	{
		if (*oldEnd != ' ')
		{
			*newEnd-- = *oldEnd--;
		}
		else
		{
			*newEnd-- = '0';
			*newEnd-- = '2';
			*newEnd-- = '%';
			oldEnd--;
		}
	}
}
int main()
{
	char arr[20] = "we are happy";
	fillblack(arr);
	printf("%s",arr);
	system("pause");
	return 0;
}