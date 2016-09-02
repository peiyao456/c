//求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字。
// 例如：2+22+222+2222+22222（n=5），n由键盘输入。
#include<stdio.h>
int main()
{
	int a = 2;
	int n = 0;
	int i = 0;
	long int s = 0;
	long int t = 0;
	scanf("%d",&n);
	while(i<n)
	{
		t = t+a;
		s = s + t;
		a = a *10;
		i++;
	}
	printf("%ld",s);
	return 0;
}