#define _CRE_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
void Joscircle(int n, int k, int m)
{
	int *p = (int *)malloc(n*sizeof(int));
	int i = 0;
	int out = 0;
	int count = 0;//������������count�ﵽmʱ�����������˳���
	for (i = 0;i < n;i++)
	{
		*(p + i) = 1;//���е��˶�����ֵΪ1��Ҫ�����˳��У�����ֵ��Ϊ0
	}
	i = k - 1;//
	while (out != n - 1)
	{
		if (p[i] == 1)//����������ڵ�λ��Ϊ1��˵�����˻��ڶ����У�����ʱ�Ϳ��԰�����
			count++;
		if (count == m)//�������ĳ����ʱ��count�պ�Ϊm����ʱ�����˳��У���������Ӧ������Ϊ0
		{
			p[i] = 0;
			count = 0;
			out++;//�����������1
		}
		i++;
		if (i == n)//�����ܹ�n���ˣ������±��i��0��n-1���������n�����Ǿͽ�����Ϊ0
		{
			i = 0;
		}
	}
	for (i = 0;i < n;i++)
	{
		if (p[i])//�Ǹ�û�б���Ϊ0������Ӧ���˾�������û�г��е���
		{
			printf("��%d��������û�г���",i+1);
		}
	}
	free(p);
}
int main()
{
	Joscircle(10,2,3);//10����Χ��һȦ���ӵڶ����˿�ʼ����������3���Ǹ��˳���
	system("pause");
	return 0;
}