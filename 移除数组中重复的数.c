#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

int removeSameNum(int arr[], int n)
{
	assert(arr);
	int count = n;
	int i = 0;
	for (i = 0; i < n - 1;i++)
	{
		if (arr[i] == arr[i+1])
				count--;
	}
	return count;
}
int main()
{
	int n = 0;
	int i = 0;
	int ret = 0;
	int *arr = NULL;
	scanf("%d",&n);
	if (n <= 0)
	{
		printf("输入元素个数不合理.\n");
		return 0;
	}
	arr = (int *)malloc(n*sizeof(int));
	if (NULL == arr)
	{
		printf("out of memory.");
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	ret = removeSameNum(arr,n);
	printf("%d",ret);
	system("pause");
	return 0;
}