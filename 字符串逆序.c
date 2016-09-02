#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void swap(char *a, int n)
{
	char temp;
	int i = 0;
	for (i = 0;i < n/2;i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1] ;
		a[n - i - 1] = temp;
	}
}
int main()
{
	char arr[10];
	printf("ÇëÊäÈëÐèÒªÄæÐòµÄ×Ö·û´®£º");
	scanf("%s", arr);
	fflush(stdin);
	swap(arr, strlen(arr));
	printf("%s", arr);
	system("pause");
	return 0;
}