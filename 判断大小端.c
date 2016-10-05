#include<stdio.h>
//指针实现
int test1()
{
	int a = 1;
	char* pc = (char*)&a;
	if (*pc == 1)
		return 0;//小端
	else
		return 1;//大端
}
//共用体实现
int test2()
{
	union
	{
		int i;
		char c;
	}Un;
	Un.i = 1;
	if (Un.c == 1)
		return 0;//小端
	else
		return 1;//大端
}
int main()
{
	int ret = test1();
	if (ret)
		printf("大端\n");
	else
		printf("小端\n");
	ret = test2();
	if (ret)
		printf("大端\n");
	else
		printf("小端\n");
	system("pause");
	return 0;
}