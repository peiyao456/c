//字符串旋转
//比如aabcd左旋两位就是bcdaa
#include<stdio.h>
#include<assert.h>
void reverse(char *left, char *right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void move_left(char *str, int n)
{
	assert(str);
	int len = strlen(str);
	if (n > len)
	{
		n = n % len;
	}
	reverse(str, str + n - 1);
	reverse(str + n, str + len - 1);
	reverse(str, str + len - 1);
}
int main()
{
	char arr[] = "aabcd";
	move_left(arr,6);
	printf("%s",arr);
	system("pause");
	return 0;
}