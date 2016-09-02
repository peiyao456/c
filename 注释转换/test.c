//test.c

#define _CRT_SECURE_NO_WARNINGS 1
#include"commentconvert.h"
int main()
{
	FILE *pfRead = NULL;
	FILE *pfWrite = NULL;
	printf("×¢ÊÍ¿ªÊ¼\n");
	pfRead = fopen(INPUTNAME, "r");
	if (NULL == pfRead)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	pfWrite = fopen(OUTPUTNAME, "w");
	if (NULL == pfWrite)
	{
		fclose(pfRead);
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	commentcovert(pfRead, pfWrite);
	printf("×¢ÊÍ½áÊø\n");
	fclose(pfRead);
	fclose(pfWrite);
	system("pause");
	return 0;
}