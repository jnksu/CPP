// func_ptr.c -- ʹ�ú���ָ�� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRLEN 81

int showmenu(void);
void eatline(void);		//������ĩ
void show(void (* fp)(char *), char * str);
void Toupper(char *);	//���ַ���ת��Ϊ��д
void ToLower(char *);	//���ַ���ת��ΪСд
void Transpose(char *); //��Сдת��
void Dummy(char *);		//���ı��ַ���
void  reject_ch(char * str, int ch);	//���ַ������޳��ض����ַ�

const char * match = "ulton";
typedef void (* V_FP_CHARP)(char *);

int main(int argc, char ** argv)
{
	char line[STRLEN];
	char copy[STRLEN];
	int choice;
	V_FP_CHARP arpf[4] = {Toupper, ToLower, Transpose, Dummy};
	fputs("Enter a string(empty line to quit): \n", stdout);
	while(fgets(line, STRLEN, stdin) && *line != '\n'){
		reject_ch(line, '\n');
		
		choice = showmenu();
		while(choice >= 0 && choice <= 3){
			
			strcpy(copy, line);
			show(arpf[choice], copy);
			choice = showmenu();
		}
		fputs("Enter a string(empty line to quit): \n", stdout);
	}
	
	fputs("Bye~!\n", stdout);
	exit(EXIT_SUCCESS);
}

int showmenu(void)
{
	char ans;
	int rec;
	fputs("Enter the choice: \n", stdout);
	fputs("u)upper case         l)lower case\n", stdout);
	fputs("t)transposed case    o)original case\n", stdout);
	fputs("n)next string\n", stdout);
	ans = getchar();			//��ȡ�û���Ӧ
	ans = tolower(ans);			//ת��ΪСд
	eatline();					//�޳��û����뻺���е�ʣ�ಿ��
	while(strchr("ulton", ans) == NULL){
		fputs("Please enter a u, l, t, o, or n:\n", stdout);
		ans = tolower(getchar());
		eatline();
	}
	
	for(rec = 0; rec < 5; rec++){
		if(*(match + rec) == ans)
			break;
	}
	
	return rec;
}

void eatline(void)
{
	while(getchar() != '\n')
		continue;
}

void Toupper(char * str)
{
	while(*str){
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char * str)
{
	while(*str){
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char * str)
{
	while(*str){
		if(islower(*str))
			*str = toupper(*str);
		else if(isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char * str)
{
	//���ı��ַ���
}

void show(void (* fp)(char *), char * str)
{
	(*fp)(str);	//���û�ѡ��ĺ���������str
	fprintf(stdout, "%s\n", str);//��ʾ���
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
