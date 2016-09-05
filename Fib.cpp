#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<cassert>
//쳲������ݹ�ʵ��
unsigned long long Fib1(long long n)
{
	assert(n >= 0);
	return n < 2 ? n : Fib1(n - 1) + Fib1(n-2);
}
//쳲������ǵݹ�ʵ�֣��ռ临�Ӷ�0��N����
unsigned long long Fib2(long long n)
{
	assert(n >= 0);
	unsigned long long* array = new unsigned long long[n+1];
	array[0] = 0;
	array[1] = 1;
	for (int i = 2;i <= n; ++i)
	{
		array[i] = array[i - 1] + array[i - 2];
	}
	return array[n];
}
//쳲������ǵݹ�ʵ�֣��ռ临�Ӷ�0��N����
unsigned long long Fib3(long long n)
{
	assert(n >= 0);
	long long ret = 1;
	long long first = 1;
	long long second = 1;
	while (n > 2)
	{
		ret = first + second;
		first = second;
		second = ret;
		n--;
	}
	return ret;
}
int main()
{
	cout << Fib3(10) << endl;;
	system("pause");
	return 0;
}