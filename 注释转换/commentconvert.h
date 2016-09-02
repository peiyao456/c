//commentconvert.h
#ifndef  __COMMENTCOVERT_H__
#define  __COMMENTCOVERT_H__
#define INPUTNAME "input.c"
#define OUTPUTNAME "output.c"
#include<stdio.h>
#include<stdlib.h>
enum STATE
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE,
	STR_STATE
};

void commentcovert(FILE *pfRead, FILE *pfWrite);
void Do_NUL_STATE(FILE *pfRead, FILE *pfWrite);
void Do_C_STATE(FILE *pfRead, FILE *pfWrite);
void Do_CPP_STATE(FILE *pfRead, FILE *pfWrite);
void Do_STR_STATE(FILE *pfRead, FILE *pfWrite);
#endif//