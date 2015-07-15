/* sort_str.c -- ����һЩ�ַ����������ǽ������� */
#include <stdio.h>
#include <string.h>

#define SIZE 81								/* �ַ�����������,����\0 */
#define LIM 20								/* ����ȡ������ */
#define HALT " "							/* �ÿ��ַ�����ֹ���� */
void ststr(char * strings[], int num);		/*  �ַ��������� */

int main(void)
{
	char input[LIM][SIZE];					/* �洢��������� */
	char * ptstr[LIM];						/* ָ����������� */
	int ct = 0;								/* ������� */
	int k;									/* ������� */
	
	printf("Input up to %d lines, and I will sort them.\n", LIM);
	printf("To stop, press the Enter key at a line's start.\n");
	
	while(ct < LIM && gets(input[ct]) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];				/* ��ָ��ָ�������ַ��� */
		ct++;
	}
	ststr(ptstr, ct);						/* �����ַ��������� */
	puts("\nHere's the sorted list: ");
	for(k = 0; k < ct; k++)
		puts(ptstr[k]);
	
	return 0;
}

/* �ַ��� - ָ�� - ������ */
void ststr(char * strings[], int num)
{
	char * temp;
	int top, seek;
	
	for(top = 0; top < num - 1; top++)
		for(seek = top + 1; seek < num; seek++ )
			if(strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}
	