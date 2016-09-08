//test.c
#include"SeqList.h"
void menu()
{
	printf("-------动态顺序表管理系统-------\n");
	printf("-------0.退出-------------------\n");
	printf("-------1.显示-------------------\n");
	printf("-------2.尾插-------------------\n");
	printf("-------3.尾删-------------------\n");
	printf("-------4.头插-------------------\n");
	printf("-------5.头删-------------------\n");
	printf("-------6.删除指定---------------\n");
	printf("-------7.删除指定全部-----------\n");
	printf("-------8.冒泡排序---------------\n");
	printf("-------9.插入排序---------------\n");
	printf("-------10.选择排序--------------\n");
	printf("-------11.折半查找---------------\n");
	printf("-------12.删除指定位置-----------\n");
}

void test()
{
	SeqList seq;
	pSeqList pSeq = &seq;
	DataType x = 0;
	int input = 1;
	int pos = 0;
	InitSeqList(pSeq);
	while (input)
	{
		menu();
		printf("请选择：>");
		scanf("%d",&input);
		switch (input)
		{
		case EXIT:
			DestroySeqList(pSeq);
			break;
		case PRINT:
			PrintSeqList(pSeq);
			break;
		case PUSHBACK:
			printf("请输入要插入的元素：\n");
			scanf("%d",&x);
			PushBack(pSeq,x);
			break;
		case POPBACK:
			PopBack(pSeq);
			break;
		case PUSHFRONT:
			printf("请输入要插入的元素：\n");
			scanf("%d", &x);
			PushFront(pSeq,x);
			break;
		case POPFRONT:
			PopFront(pSeq);
			break;
		case BOTTLESORT:
			BubbleSort(pSeq);
			break;
		case SELECTSORT:
			SelectSort(pSeq);
			break;
		case INSERTSORT:
			InsertSort(pSeq);
			break;
		case ERASE:
			printf("请输入要删除元素的位置：\n");
			scanf("%d", &pos);
			Erase(pSeq, pos);
			break;
		case BINARYSEARCH:
			printf("请输入要查找的元素：\n");
			scanf("%d", &x);
			BinarySearch(pSeq, x);
			break;
		case REMOVE:
			printf("请输入要删除的元素：\n");
			scanf("%d", &x);
			Remove(pSeq, x);
			break;
		case REMOVEALL:
			printf("请输入要删除的元素：\n");
			scanf("%d", &x);
			RemoveAll(pSeq, x);
			break;
		}
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}