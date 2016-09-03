#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
static int find(pConInfo pcon, char *name)
{
	int i = 0;
	for (i = 0;i < pcon->size;i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
			return i;
	}
	return -1;
}
void init_con(pConInfo pcon)
{
	pcon->size = 0;
	pcon->capacity = 2;
	pcon->data = (person *)malloc(2 * sizeof(person));
	if (pcon->data == NULL)
	{
		printf("out of memory");
		return;
	}
	load_con(pcon);
}
void check_capacity(pConInfo pcon)
{
	person *p = NULL;
	pcon->data = (person *)realloc(pcon->data, (pcon->capacity + INC_CAP)*sizeof(person));
	if (pcon->data == NULL)
	{
		printf("out of memory");
		exit(EXIT_FAILURE);
	}
	else
	{
		p = pcon->data;
	}
	pcon->capacity = pcon->capacity + INC_CAP;
}
void add_person(pConInfo pcon)
{
	/*if (pcon->size == pcon->capacity)
	{
		expand_capacity(pcon);
	}*/
	/*if (pcon->size == 0)
	{
	init_con(pcon);
	}*/
	check_capacity(pcon);
	printf("请输入联系人姓名：>");
	scanf("%s", pcon->data[pcon->size].name);
	printf("请输入联系人年龄：>");
	scanf("%d", &(pcon->data[pcon->size].age));
	printf("请输入联系人性别：>");
	scanf("%s", pcon->data[pcon->size].sex);
	printf("请输入联系人电话：>");
	scanf("%s", pcon->data[pcon->size].tele);
	printf("请输入联系人地址：>");
	scanf("%s", pcon->data[pcon->size].addr);
	pcon->size++;
	printf("插入成功\n");

}
void dis_con(pConInfo pcon)
{
	int i = 0;
	printf("通讯录信息如下：\n");
	printf("%12s%4s%4s%12s%20s\n", "name", "age", "sex", "tele", "addr");
	for (i = 0;i < pcon->size;i++)
	{
		printf("%12s%4d%4s%12s%20s",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex, pcon->data[i].tele,
			pcon->data[i].addr);
		printf("\n");
	}
}
void del_con(pConInfo pcon)
{
	char name[NAME_MAX];
	int pos = 0;//查找的位置
	int index = 0;
	if (pcon->size == 0)
	{
		printf("通讯录已经是空的\n");
	}
	printf("请输入删除联系人的姓名：>");
	scanf("%s", name);
	pos = find(pcon, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
	}
	else
	{
		for (index = pos;index < pcon->size;index++)
		{
			memcpy(&(pcon->data[index]), &(pcon->data[index + 1]), sizeof(person));
		}
		pcon->size--;
		printf("删除成功\n");
	}
}
void search_person(pConInfo pcon)
{
	char name[NAME_MAX];
	int pos = 0;//存储查找到的元素的位置
	printf("请输入要查找联系人的姓名:>");
	scanf("%s", name);
	pos = find(pcon, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
	}
	else
		printf("%12s%4d%4s%12s%20s",
			pcon->data[pos].name,
			pcon->data[pos].age,
			pcon->data[pos].sex,
			pcon->data[pos].tele,
			pcon->data[pos].addr);
	printf("\n");
}
void clear_con(pConInfo pcon)
{
	pcon->size = 0;
	printf("清空成功！\n");
}
void modify_person(pConInfo pcon)
{
	if (pcon->size == 0)
	{
		printf("通讯录为空");
	}
	char name[NAME_MAX];
	int pos = 0;
	printf("请输入要修改的联系人的姓名\n");
	scanf("%s", name);
	pos = find(pcon, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在\n");
		return;
	}
	else
	{
		printf("请输入修改后的信息\n");
		scanf("%s%d%s%s%s",
			pcon->data[pos].name,
			&(pcon->data[pos].age),
			pcon->data[pos].sex,
			pcon->data[pos].tele,
			pcon->data[pos].addr);
		printf("修改成功\n");
	}
}
void free_con(pConInfo pcon)
{
	free(pcon->data);
	pcon->data = NULL;
}
void sort_con(pConInfo pcon)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	person tmp;
	for (i = 0;i < pcon->size - 1;i++)
	{
		flag = 1;
		for (j = 0;j < pcon->size - 1 - i;j++)
		{
			if (strcmp(pcon->data[j].name, pcon->data[j + 1].name)> 0)
			{
				tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
				break;
	}
	printf("排序成功\n");
	dis_con(pcon);
}
void save_con(pConInfo pcon)
{
	FILE *pwrite = fopen("contact.dat","w");
	int i = 0;
	if (pwrite == NULL)
	{
		perror("open the file for write");
		exit(EXIT_FAILURE);
	}
	else
	{
		for (i = 0;i < pcon->size;i++)
		{
		    fwrite(&(pcon->data[i]),sizeof(person),1,pwrite);
		}
	}
	fclose(pwrite);
}
void load_con(pConInfo pcon)
{
	FILE *pread = fopen("contact.dat","r");
	int i = 0;
	person tmp = { 0 };
	if (pread == NULL)
	{
		perror("open the file for read");
		exit(EXIT_FAILURE);
	}
	else
	{
		while(fread(&tmp, sizeof(person), 1, pread))
		{
			check_capacity(pcon);
			pcon->data[i] = tmp;
			pcon->size++;
			i++;
		}
	}
	fclose(pread);
}