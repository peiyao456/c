//给出一个整形数组，求出不能由数组中元素自由相加得到的最小整数
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>

void sort(int arr[], int num)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 1; i < num; i++)
	{
		int m = arr[i];
		for (j = i - 1; (j >= 0) && (arr[j] > m);j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = m;
	}
}
int fun(int arr[], int num)
{
	int i = 0;
	int  r = 0, ans = -1;
	for (int i = 0;i< num ;i++)
	{
		int tl =  arr[i], tr = r + arr[i];
		if (tl <= r + 1)
		{
			r = tr;
		}
		else
		{
			ans = r + 1;
			break;
		}
	}
	if (ans == -1) ans = r + 1;
	return ans;
}
int main()
{
	int *arr = NULL;
	int num = 0;
	int i = 0;
	scanf("%d",&num);
	if (num <= 0)
	{
		printf("input error");
		return 0;
	}
	arr = (int *)malloc(num * sizeof(int));
	if (NULL == arr)
	{
		printf("out of memory\n");
		return 0;
	}
	for (i = 0; i < num; i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,num);
	int ret = fun(arr, num);
	printf("%d",ret);
	system("pause");
	return 0;
}