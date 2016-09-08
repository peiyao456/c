//SeqList.c
#include"SeqList.h"

void check_capacity(pSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->capacity == pSeq->size)
	{
		DataType *tmp = (DataType *)realloc(pSeq->data,(pSeq->capacity +DEFAULT_SIZE)*sizeof(DataType));
		if (NULL == tmp)
		{
			printf("out of memory.");
			exit(EXIT_FAILURE);
		}
		else
		{
			pSeq->data = tmp;
			pSeq->capacity += DEFAULT_SIZE;
		}
	}
}
void InitSeqList(pSeqList pSeq)
{
	assert(pSeq);
	pSeq->data = (DataType*)malloc(2*sizeof(DataType));
	if (NULL == pSeq->data)
	{
		printf("out of memory\n");
		exit(EXIT_FAILURE);
	}
	pSeq->size = 0;
	pSeq->capacity = 2;
}
void DestroySeqList(pSeqList pSeq)
{
	assert(pSeq);
	free(pSeq->data);
	pSeq->size = 0;
	pSeq->capacity = 0;
	pSeq->data = NULL;
}
void PushBack(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	check_capacity(pSeq);
	pSeq->data[pSeq->size] = x;
	pSeq->size++;
	printf("尾插成功！\n");
}
void PopBack(pSeqList pSeq)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	pSeq->size--;
	printf("尾删成功！\n");
}
void PushFront(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	check_capacity(pSeq);
	int i = 0;
	for (i = pSeq->size - 1;i >= 0;i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = x;
	pSeq->size++;
	printf("头插成功！\n");
}
void PopFront(pSeqList pSeq)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	for (i = 1;i < pSeq->size - 1;i++)
	{
		pSeq->data[i - 1] = pSeq->data[i];
	}
	pSeq->size--;
	printf("头删成功！\n");
}
void Remove(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0;i < pSeq->size;i++)
	{
		if (x == pSeq->data[i])
			break;
	}
	for (j = i + 1;j < pSeq->size;j++)
	{
		pSeq->data[j - 1] = pSeq->data[j];
	}
	pSeq->size--;
	printf("删除指定元素成功！\n");
}
void RemoveAll(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	int i = 0;
	int count = 0;
	int j = 0;
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	/*for (i = 0;i < pSeq->size;i++)
	{
		if (pSeq->data[i] == x)
		{
			count++;
		}
	}*/
	i = 0;
	j = pSeq->size - 1;
	/*while (j >= pSeq->size - count && i < pSeq->size - count)
	{
		if (pSeq->data[j] != x && pSeq->data[i] == x)
		{
			pSeq->data[i] = pSeq->data[j];
		}
		j--;
		i++;
	}*/
	while (i < pSeq->size)
	{
		if (pSeq->data[i] == x)
		{
			while (pSeq->data[j] == x)
			{
				j--;
			}
			pSeq->data[i] = pSeq->data[j];
			count++;
		}
		i++;
	}
	pSeq->size -= count;
	printf("delete success！\n");
}
void BubbleSort(pSeqList pSeq)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	int j = 0;
	int k = pSeq->size - 1;
	int tmp = 0;
	int m = 0;
	int flag = 0;
	for (i = 0;i < pSeq->size - 1;i++)
	{
		flag = 1;
		for (j = 0;j < k;j++)
		{
			if (pSeq->data[j]>pSeq->data[j + 1])
			{
				tmp = pSeq->data[j];
				pSeq->data[j] = pSeq->data[j + 1];
				pSeq->data[j + 1] = tmp;
				m = j;//m is used for recording the position of last swap
				flag = 0;
			}
		}
		k = m;
		if (flag == 1)
		{
			break;
		}
	}
	printf("successful bottlesort\n");
}
void InsertSort(pSeqList pSeq)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 1;i < pSeq->size;i++)
	{
		tmp = pSeq->data[i];
		for (j = i - 1;j >= 0 && pSeq->data[j] > tmp;j--)
		{
			pSeq->data[j + 1] = pSeq->data[j];
		}
		pSeq->data[j + 1] = tmp;
	}
	printf("successful insertsort\n");
}
void SelectSort(pSeqList pSeq)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	int j = 0;
	int min = 0;//the index of min number
	int tmp = 0;
	for (i = 0;i < pSeq->size;i++)
	{
		min = i;
		for (j = i;j < pSeq->size;j++)
		{
			if (pSeq->data[j] < pSeq->data[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			tmp = pSeq->data[i];
			pSeq->data[i] = pSeq->data[min];
			pSeq->data[min] = tmp;
		}
	}
	printf("successful selectsort\n");
}
void BinarySearch(pSeqList pSeq, DataType x)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	SelectSort(pSeq);//before searching,we must sort seqlist
	int left = 0;
	int right = pSeq->size - 1;
	int middle = 0;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (x == pSeq->data[middle])
		{
			printf("have found\n");
			return;
		}
		else if (x < pSeq->data[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	printf("not found\n");
}
void Erase(pSeqList pSeq, int pos)
{
	assert(pSeq);
	if (0 == pSeq->size)
	{
		printf("seqlist is empty.\n");
		exit(EXIT_FAILURE);
	}
	pSeq->data[pos] = pSeq->data[pSeq->size - 1];
	pSeq->size--;
	printf("successful delete designated position\n");
}
void PrintSeqList(pSeqList pSeq)
{
	assert(pSeq);
	int i = 0;
	printf("动态顺序表中的元素为：\n");
	for (i = 0;i < pSeq->size;i++)
	{
		printf("%d ",pSeq->data[i]);
	}
	printf("\n");
}
