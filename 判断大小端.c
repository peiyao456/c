#include<stdio.h>
//ָ��ʵ��
int test1()
{
	int a = 1;
	char* pc = (char*)&a;
	if (*pc == 1)
		return 0;//С��
	else
		return 1;//���
}
//������ʵ��
int test2()
{
	union
	{
		int i;
		char c;
	}Un;
	Un.i = 1;
	if (Un.c == 1)
		return 0;//С��
	else
		return 1;//���
}
int main()
{
	int ret = test1();
	if (ret)
		printf("���\n");
	else
		printf("С��\n");
	ret = test2();
	if (ret)
		printf("���\n");
	else
		printf("С��\n");
	system("pause");
	return 0;
}