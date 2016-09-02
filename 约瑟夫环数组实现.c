#define _CRE_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
void Joscircle(int n, int k, int m)
{
	int *p = (int *)malloc(n*sizeof(int));
	int i = 0;
	int out = 0;
	int count = 0;//用来计数，当count达到m时，所数到的人出列
	for (i = 0;i < n;i++)
	{
		*(p + i) = 1;//所有的人都被赋值为1，要是有人出列，将其值改为0
	}
	i = k - 1;//
	while (out != n - 1)
	{
		if (p[i] == 1)//如果该人所在的位置为1，说明此人还在队伍中，计数时就可以包括他
			count++;
		if (count == m)//如果数到某个人时，count刚好为m，此时，此人出列，将其所对应的数改为0
		{
			p[i] = 0;
			count = 0;
			out++;//出伍的人数加1
		}
		i++;
		if (i == n)//由于总共n个人，数组下标的i从0到n-1，如果数到n，我们就将其置为0
		{
			i = 0;
		}
	}
	for (i = 0;i < n;i++)
	{
		if (p[i])//那个没有被改为0的数对应的人就是最终没有出列的人
		{
			printf("第%d个人最终没有出列",i+1);
		}
	}
	free(p);
}
int main()
{
	Joscircle(10,2,3);//10个人围成一圈，从第二个人开始数数，数到3的那个人出列
	system("pause");
	return 0;
}