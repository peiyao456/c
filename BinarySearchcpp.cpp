#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//���ֲ��ҷǵݹ顣
//ʱ�临�Ӷ�0(log2 n)
//�ռ临�Ӷȣ�0(1)
bool BinarySearch(int arr[],int nums, int x)
{
	//qsort(arr,nums);
	int left = 0;
	int right = nums - 1;
	int middle = 0;
	while (left <= right)
	{
		middle = (left & right) | ((left ^ right) >> 1);
		if (arr[middle] == x)
		{
			return true;
		}
		if (arr[middle] < x)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	return false;
}
//���ֲ��ҵݹ顣
//ʱ�临�Ӷȣ�0(log2 n)
//�ռ临�Ӷȣ�0(log2 n)
bool BinarySearchR(int arr[], int nums, int x)
{
	int left = 0;
	int right = nums - 1;
	int middle = (left & right) | ((left ^ right) >> 1);
	if (arr[middle] == x)
	{
		return true;
	}
	if (left == right)
	{
		return false;
	}
	if (arr[middle] < x)
	{
		BinarySearchR(arr + middle + 1,right-middle,x);
	}
	else
	{
		BinarySearchR(arr, middle-left, x);
	}
}
int main()
{
	int arr[5] = {1,2,3,6,7 };
	cout << BinarySearch(arr, 5, 3) << endl;
	cout << BinarySearchR(arr, 5, 9) << endl;
	system("pause");
	return 0;
}