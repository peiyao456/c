#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int year, month, day,isleap=0;
	int sum = 31;
	int a[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	printf("��������Ҫ���ҵ����ڣ�");
	scanf("%d %d %d", &year, &month, &day);
	printf("��Ҫ���ҵ�������%d��%d��%d��", year, month, day);
	if (year <= 0 || month <= 0 || day <= 0)
		printf("data error!");
	else
	{
		{
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
			{
				printf("����������");
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
			printf("\n�������������");
		 if (month == 1)
			printf("��������һ��ĵ�%d��", day);
		if(month>1&&!((isleap != 1) && (month == 2) && (day == 29)))
		{
			//int sum = 31;
			for (int i = 1;i < month - 1;i++)
			{
				//int sum = 31;
				sum += a[i];
			}

			int sumday = sum + day;
			printf("��������һ��ĵ�%d��", sumday);
		}

	}
	system("pause");
	return 0;
}