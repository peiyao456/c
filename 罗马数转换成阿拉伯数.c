#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define N 7
char digit[N] = {'I','V','X','L','C','D','M'};
int values[N] = { 1,  5, 10, 50, 100,500,1000 };

int digitToValue(char ch)//字符转化成相应的阿拉伯数
{
	int i = 0;
	for (i = 0;i < N; i++)
	{
		if (digit[i] == ch)
			return values[i];
	}
	return 0;
}
int findMaxIndex(char str[], int L, int R)//找最大字符的下标
{
	assert(L >= 0 &&R >= 0);
	int i = 0;
	int max = digitToValue(str[L]);
	int maxIndex = L;
	for (i = L+1;i <= R;i++)
	{
		int tmp = digitToValue(str[i]);//将字母转为对应的数字
		if (tmp > max)
		{
			max = tmp;
			maxIndex = i;
		}
	}
	return maxIndex;
}
int romenToNumber(char str[],int L,int R)//转化函数
{
	if (L == R)
	{
		return digitToValue(str[L]);
	}
	else if (L > R)
	{
		return 0;
	}
	else
	{
		int maxIndex = findMaxIndex(str, L, R);
		int left = romenToNumber(str, L, maxIndex - 1);
		int right = romenToNumber(str,maxIndex + 1, R);
		int num = digitToValue(str[maxIndex]);
		return num - left + right;
	}
}
int main()
{
	char str[] = "IMCCI";
	//scanf("%s",str);
	//int len = strlen(str);
	int r = romenToNumber(str,0,4);
	printf("%d",r);
	system("pause");
	return 0;
}
