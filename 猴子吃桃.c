#include<stdio.h>
#include<windows.h>
int main()
{
	int day = 0;
	scanf("%d", &day);
	day = day - 1;
	int x2 = 1;
	int x1 = 0;
	//int i = 0;
	while (day > 0)
	{
		x1 = (x2 + 1) * 2;
		x2 = x1;
		day--;
	}
	printf("%d", x1);
	system("pause");
	return 0;
}