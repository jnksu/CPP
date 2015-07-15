/*
 * pe15-6.c
 *	һ���򵥵Ĳ˵�����
 *  Created on: 2014��3��10��
 *      Author: Mr_Li
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pe15-6.h"	//������������
//��������
int main(int argc, char ** argv)
{
	FONT pf;
	showMenu(&pf);
	exit(EXIT_SUCCESS);
}
//��ʾ��ǰ������Ϣ
void showInformation(FONT * pf)
{
	fputs(" ID SIZE ALIGNMENT  B   I   U \n", stdout);
	fprintf(stdout, "%3u %4u %9s %3s %3s %3s\n", pf->fontId, pf->fontSize,
			*(ALG + pf->algnMen), *(TOG + pf->bold), *(TOG + pf->italic), *(TOG + pf->underline));
}
//��ȡ��ȷ��ѡ��
char get_let(const char * str)
{
	char ch;
	
	while(strchr(str, (ch = getchar())) == NULL){
		eatLine();
		printf("Enter a character in the list %s\n", str);
	}
	eatLine();
	
	return ch;
}
//��һ���ķ��ط�Χ�ڻ�ȡ��ȷ������ [0,size]
int get_int(int size)
{
	int value;
	char * buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	
	while (fgets(buffer, BUFFER_SIZE, stdin)){
		if (sscanf_s(buffer, "%d", &value) != 1){
			fprintf(stderr, "Bad input skipped: %s", buffer);
			continue;
		}
		else if(value < 0 || value > size){
			fprintf(stderr, "%d is not a valid value skipped.\n", value);
			continue;
		}
		else{
			break;
		}
	}
	free(buffer);
	return value;
}
//��ʾ���˵�
void showMenu(FONT * fs)
{
	char choice;

	showStr(fs);
	while((choice = get_let("fsabiuq")) != 'q'){
		switch(choice){
			
			case 'f':change_font(fs);	
						break;
			case 's':change_size(fs);
						break;
			case 'a':change_aligment(fs);
						break;
			case 'b':(fs->bold)      ^= 01;	//ת��λ
						break;
			case 'i':(fs->italic)    ^= 01;
						break;
			case 'u':(fs->underline) ^= 01;
						break;
			default :
						printf("OH! NO ! The program was wrong.\n");
						exit(EXIT_FAILURE);
		}
		showStr(fs);
	}
	
	fprintf(stdout, "Bye!\n");
}

//��ʾ��Ϣ
void showStr(FONT * pf)
{
	showInformation(pf);
	fprintf(stdout, "%s\n", MSTR);
	fprintf(stdout, "%s\n", MSTR1);
	fprintf(stdout, "%s\n", MSTR2);
}
//�ı�������
void change_font(FONT * pf)
{
	printf("Enter font ID(0-255):");
	pf->fontId = get_int(255);
}
//�ı������С
void change_size(FONT * pf)
{
	printf("Enter font size(0-127):");
	pf->fontSize = get_int(127);
}
//�ı�������뷽ʽ
void change_aligment(FONT * pf)
{
	char ch;
	fprintf(stdout, "%s\n", SSTR);
	ch = get_let("lcr");
	switch (ch)
	{
	case 'l':pf->algnMen = 0;
	case 'c':pf->algnMen = 2;
	case 'r':pf->algnMen = 1;
	default:fprintf(stderr, "The program was get into trouble.\n");
			break;
	}
}
//����л���
void eatLine(void)
{
	while(getchar() != '\n')
		continue;
}
