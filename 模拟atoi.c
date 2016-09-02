#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
enum Status 
{
	kvalid,
	kinvalid
};
int flag = kvalid;//定义全局变量，标志字符串是否是异常
long long to_num(const char *str, int s)
{
	long long num = 0;
	while (*str)
	{
		if (*str >= '0' &&*str <= '9')
		{
			num = num * 10 + s * (*str - '0');
			//是否溢出的判断
			if ((s == 1 && (num > 0x7FFFFFFF)) || (s == -1) && (num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*str == '\0')
		flag = kvalid;//字符串不是异常
	return num;
}
int my_atoi(const char *str)
{
	flag = 1;
	long long num = 0;
	if (str != NULL && *str != '\0')
	{
		int s = 1;//定义符号位
		if (*str == '+')
			str++;
		else if(*str == '-')
		{
			str++;
			s = -1;
		}
		if (*str != '\0')
		{
			num = to_num(str, s);
		}
	}
	return (int)num;
}

int main()
{
	char *str = "1234567123778954";
	int num = my_atoi(str);
	printf("%d\n",num);
	if (flag == 0)
	{
		printf("字符串没有异常");
	}
	if (flag == 1)
	{
		printf("字符串存在异常");
	}
	system("pause");
	return 0;
}