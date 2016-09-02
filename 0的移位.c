#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void moveZeros(int arr[], int len)
{
	if (len <= 0)
	{
		return;
	}
	int i = 0;
	int zeros = 0;
	for (i = 0;i < len; i++)
	{
		if (arr[i] != 0)
		{
			arr[i - zeros] = arr[i];
		}
		else
		{
			zeros++;
		}
	}
	for (i = len - zeros;i < len;i++)
	{
		arr[i] = 0;
	}
}
void moveZeros2(int arr[], int len)
{
	if (len <= 0)
	{
		return;
	}
	int i = 0;
	int tmp = 0;
	int j = 0;
	for (i = 0;i < len; i++)
	{
		if (arr[i] != 0)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			j++;
		}
	}
}
int main()
{
	int arr[8] = { 1,3,0,7,8,0,2,9 };
	moveZeros(arr,8);
	int i = 0;
	for (i = 0;i < 8; i++)
	{
		printf("%d ",arr[i]);
	}
	system("pause");
	return 0;
}