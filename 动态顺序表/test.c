//test.c
#include"SeqList.h"
void menu()
{
	printf("-------��̬˳������ϵͳ-------\n");
	printf("-------0.�˳�-------------------\n");
	printf("-------1.��ʾ-------------------\n");
	printf("-------2.β��-------------------\n");
	printf("-------3.βɾ-------------------\n");
	printf("-------4.ͷ��-------------------\n");
	printf("-------5.ͷɾ-------------------\n");
	printf("-------6.ɾ��ָ��---------------\n");
	printf("-------7.ɾ��ָ��ȫ��-----------\n");
	printf("-------8.ð������---------------\n");
	printf("-------9.��������---------------\n");
	printf("-------10.ѡ������--------------\n");
	printf("-------11.�۰����---------------\n");
	printf("-------12.ɾ��ָ��λ��-----------\n");
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
		printf("��ѡ��>");
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
			printf("������Ҫ�����Ԫ�أ�\n");
			scanf("%d",&x);
			PushBack(pSeq,x);
			break;
		case POPBACK:
			PopBack(pSeq);
			break;
		case PUSHFRONT:
			printf("������Ҫ�����Ԫ�أ�\n");
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
			printf("������Ҫɾ��Ԫ�ص�λ�ã�\n");
			scanf("%d", &pos);
			Erase(pSeq, pos);
			break;
		case BINARYSEARCH:
			printf("������Ҫ���ҵ�Ԫ�أ�\n");
			scanf("%d", &x);
			BinarySearch(pSeq, x);
			break;
		case REMOVE:
			printf("������Ҫɾ����Ԫ�أ�\n");
			scanf("%d", &x);
			Remove(pSeq, x);
			break;
		case REMOVEALL:
			printf("������Ҫɾ����Ԫ�أ�\n");
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