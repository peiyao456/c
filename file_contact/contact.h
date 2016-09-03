#ifndef __CONTACT_H__
#define __CONTACT_H__
#define NAME_MAX 12
#define SEX_MAX 4
#define TELE_MAX 12
#define ADDR_MAX 20
#define INC_CAP  2

enum OP
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	DISPLAY,
	CLEAR,
	SORT
};
typedef struct person
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}person;
typedef struct ConInfo
{
	person *data;
	int size;
	int capacity;//当前电话本的容量
}ConInfo, *pConInfo;
void init_con(pConInfo pcon);
void add_person(pConInfo pcon);
void dis_con(pConInfo pcon);
void del_con(pConInfo pcon);
void search_person(pConInfo pcon);
void clear_con(pConInfo pcon);
void modify_person(pConInfo pcon);
void sort_con(pConInfo pcon);
void free_con(pConInfo pcon);
void save_con(pConInfo pcon);
void load_con(pConInfo pcon);
#endif