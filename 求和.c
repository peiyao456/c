//��Sn=a+aa+aaa+��+aa��aaa����n��a��ֵ֮������a��һ�����֡�
// ���磺2+22+222+2222+22222��n=5����n�ɼ������롣
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