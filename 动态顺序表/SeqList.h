//SeqList.h
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
enum OP
{
	EXIT,
	PRINT,
	PUSHBACK,
	POPBACK,
	PUSHFRONT,
	POPFRONT,
	REMOVE,
	REMOVEALL,
	BOTTLESORT,
	INSERTSORT,
	SELECTSORT,
	BINARYSEARCH,
	ERASE
};

#define DEFAULT_SIZE 3
typedef int DataType;
typedef struct Seqlist
{
	DataType *data;
	int size;
	int capacity;
}SeqList,*pSeqList;
void InitSeqList(pSeqList pSeq);
void DestroySeqList(pSeqList pSeq);
void PushBack(pSeqList pSeq,DataType x);
void PopBack(pSeqList pSeq);
void PushFront(pSeqList pSeq,  DataType x);
void PopFront(pSeqList pSeq);
void Remove(pSeqList pSeq, DataType x);
void RemoveAll(pSeqList pSeq, DataType x);
void BubbleSort(pSeqList pSeq);
void InsertSort(pSeqList pSeq);
void SelectSort(pSeqList pSeq);
void BinarySearch(pSeqList pSeq);
void Erase(pSeqList pSeq,int pos);
void PrintSeqList(pSeqList pSeq);
#endif// __SEQLIST_H__