#define _CRT_SECURE_NO_WARNINGS 1

//输出m到n之间的水仙花数，如果没有输入no
#include<stdio.h>
void fun(int m, int n)
{
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int flag = 0;
	for (i = m; i <= n;++i)
	{
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;
		if (i == a*a*a + b*b*b + c*c*c)
		{
			flag = 1;
			printf("%d ",i);
		}
	}
	if (flag == 0)
	{
		printf("no");
	}
}
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d",&m,&n);
	if ((m < 100) || (m>1000) || (n < 100) || (n>1000) || (m > n))
	{
		return 0;
	}
	else
	{
		fun(m,n);
	}
	system("pause");
	return 0;
}