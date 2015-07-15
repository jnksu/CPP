/* names3.c -- ʹ��ָ���malloc()���� */
#include <stdio.h>
#include <stdlib.h>	//Ϊ��ʹ��strcpy(),strlen()
#include <string.h> //Ϊ��ʹ��malloc(), free()
#define MAXLEN 81

struct namect{
	char * fname;	//ʹ��ָ��
	char * lname;
	int  letters;
};
void getinfo(struct namect *); //�����ڴ�
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); //������ͷ��ڴ�
void reject_ch(char *, int);

int main(int argc, char ** argv)
{
	struct namect person;
	
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);
	
	exit(EXIT_SUCCESS);
}

void getinfo(struct namect * pst)
{
	char temp[MAXLEN];
	printf("Please enter your first name.\n");
	fgets(temp, MAXLEN, stdin);
	reject_ch(temp, '\n');
	//��������������ֵ��ڴ�
	pst->fname = (char *)malloc((strlen(temp) + 1) * sizeof(char));
	//�����ַ��䵽�ѷ�����ڴ��� 
	 strcpy(pst->fname, temp);
	printf("Please enter your last name.\n");
	fgets(temp, MAXLEN, stdin);
	reject_ch(temp, '\n');
	pst->lname = (char *)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy(pst->lname, temp);
}

void makeinfo(struct namect * pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
	printf("%s %s, your name contains %d letters.\n",
		pst->fname, pst->lname, pst->letters); 
}

void cleanup(struct namect * pst)
{
	free(pst->fname);
	free(pst->lname);
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
