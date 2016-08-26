#define _CRT_SCURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

char* my_strstr(const char* str,const char* substr)
{
	assert(str);
	assert(substr);
	const char* str1 = str;
	const char* str2 = substr;
	char * start = NULL;
	while (*str1)
	{
		start = str1;
		while ((*str1)&&(*str2) && (*str1 == *str2))
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
		{
			return (char*)start;
		}
		str1 = start + 1;
		str2 = substr;
	}
	return NULL;
}
int main()
{
	char* ret = my_strstr("asdfghdfg","dfg");
	if (ret)
	{
		printf("%s",ret);
	}
	system("pause");
	return 0;
}