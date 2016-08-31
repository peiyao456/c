#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int year, month, day,isleap=0;
	int sum = 31;
	int a[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	printf("请输入你要查找的日期：");
	scanf("%d %d %d", &year, &month, &day);
	printf("你要查找的日期是%d年%d月%d日", year, month, day);
	if (year <= 0 || month <= 0 || day <= 0)
		printf("data error!");
	else
	{
		{
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
			{
				printf("该年是闰年");
				int isleap = 1;
				a[1] = 29;
			}
			else
			{
				a[1] = 28;
				//if (month == 2 && day == 29)
					//printf("data error");
				
			}

		}
		if((isleap!=1)&&(month==2)&&(day==29))
			printf("\n输入的日期有误！");
		 if (month == 1)
			printf("该天是这一年的第%d天", day);
		if(month>1&&!((isleap != 1) && (month == 2) && (day == 29)))
		{
			//int sum = 31;
			for (int i = 1;i < month - 1;i++)
			{
				//int sum = 31;
				sum += a[i];
			}

			int sumday = sum + day;
			printf("该天是这一年的第%d天", sumday);
		}

	}
	system("pause");
	return 0;
}