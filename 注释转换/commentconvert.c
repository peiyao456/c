//commentconvert.c
#include"commentconvert.h"
enum STATE state = NUL_STATE;
void commentcovert(FILE *pfRead, FILE *pfWrite)
{
	while (state != END_STATE)
	{
		switch(state)
		{ 
		case NUL_STATE:
			Do_NUL_STATE(pfRead, pfWrite);
			break;
		case C_STATE:
			Do_C_STATE(pfRead, pfWrite);
			break;
		case CPP_STATE:
			Do_CPP_STATE(pfRead, pfWrite);
			break;
		case STR_STATE:
			Do_STR_STATE(pfRead, pfWrite);
			break;
		case END_STATE:
			break;
		}
	}
}
void Do_NUL_STATE(FILE *pfRead, FILE *pfWrite)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '/':
		second = fgetc(pfRead);
		if (second == '/')
		{
			fputc('/', pfWrite);
			fputc('/', pfWrite);
			state = CPP_STATE;   //����״̬������//ֱ�ӽ�//д��ȥ��������cpp״̬
		}
			else if (second == '*')
			{
				fputc(first, pfWrite);
				fputc('/', pfWrite);
				state = C_STATE;//����״̬������/*Ҫ��/*���//д��ȥ��������c״̬
			}
			else
			{
				fputc(first, pfWrite);
				fputc(second, pfWrite);//������������ַ���ֱ��д��ȥ��״̬���ı䡣
			}
			break;
		case EOF:
			state = END_STATE;//�������EOF���������״̬
			break;
		case '"':
			fputc(first, pfWrite);
			state = STR_STATE;//�������"�������ַ���״̬
			break;
		default:
			fputc(first, pfWrite);//����������ַ���ֱ��д��ȥ����
			break;
		}
}
void Do_STR_STATE(FILE *pfRead,FILE *pfWrite)
{
	int first = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '"':
		fputc(first, pfWrite);
		state = NUL_STATE;//���ַ���״̬������������ţ���������д�룬��������״̬
		break;
	default:
		fputc(first, pfWrite);//����������ַ���ֱ��д��ȥ����
		break;
	}
}
void Do_C_STATE(FILE *pfRead, FILE *pfWrite)
{
	int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '*':
		second = fgetc(pfRead);
		if (second == '/')  // ����*/ ˵��c��ע�ͽ������л�����״̬
		{
			state = NUL_STATE;
			third = fgetc(pfRead);
			if (third != '\n')
			{
				fputc('\n', pfWrite);    //���/��ߵ��ַ����ǻس�����Ҫд��ȥ�س���Ȼ���ٰѶ������ַ��Ż�
				ungetc(third, pfRead);
			}
			else
			{
				ungetc(third, pfRead);//����ǻس����ѻس��Ż�
			}
		}                           
		else
		{
			fputc(first, pfWrite);          
			//�������*�����Ǻ�߲���/����*�Ž�ȥ��*��ߵ��ַ��Żأ����磬/***/,����c״̬�Ժ�
			//����*����ߵ��ַ�Ҳ��*�����������*��д��ȥ����߾�ֻʣ��/���Ͳ����ҵ�c״̬�����ı�־��
			//���ԣ���Ҫ�ѵڶ����ַ�ԭ��д��
			/*fputc(second, pfWrite);*/
			ungetc(second,pfRead);    //�Ż�
		}
		break;
	case '\n':
		fputc(first, pfWrite);//�����Ҫ�س����ɻس�д�룬��д��//��״̬���䡣
		fputc('/', pfWrite);
		fputc('/', pfWrite);
		break;
	default:
		fputc(first, pfWrite);
		break;
	}
}
void Do_CPP_STATE(FILE *pfRead, FILE *pfWrite)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '\n':
		fputc(first,pfWrite);//cpp״̬����������س���cpp״̬������������״̬
		state = NUL_STATE;
		break;
	default:
		if (first == EOF)
		{
			state = END_STATE;
		}
		else
		{
			fputc(first, pfWrite);
		}
			break;
		}
}