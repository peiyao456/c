#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Contact.h"

void menu()
{
	printf("*****1.add       2.del   ****\n");
	printf("*****3.search    4.modify****\n");
	printf("*****5.display   6.clear ****\n");
	printf("*****7.sort      0.exit  ****\n");
}
int main()
{
	ConInfo  pson = { 0 };
	init_con(&pson);
	int input = 1;
	while (input)
	{
		menu();
		printf("«Î—°‘Ò:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_person(&pson);
			break;
		case DEL:
			del_con(&pson);
			break;
		case SEARCH:
			search_person(&pson);
			break;
		case MODIFY:
			modify_person(&pson);
			break;
		case CLEAR:
			clear_con(&pson);
			break;
		case DISPLAY:
			dis_con(&pson);
			break;
		case SORT:
			sort_con(&pson);
			break;
		case EXIT:
			free_con(&pson);
			break;
		default:
			printf(" ‰»Î¥ÌŒÛ");
			break;
		}
	}
	system("pause");
	return  0;
}
