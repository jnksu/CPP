/*  book.c -- ������һ�����ͼ��Ŀ¼ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 41 /* ��������󳤶�+1 */
#define MAXAUTL 31 /* ����������󳤶�+1 */

void reject_ch(char *, int);
struct book{	   /* ���߽ṹģ��:���Ϊbook */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};				   /* �ṹģ����� */

int main(int argc, char ** argv)
{
	struct book library; /* ��library����Ϊbook���͵ı��� */
	printf("Please enter the book title.\n");
	fgets(library.title, MAXTITL, stdin); /* ����title ���� */
	printf("Now enter the author.\n");
	fgets(library.author, MAXAUTL, stdin);
	reject_ch(library.title, '\n');
	reject_ch(library.author, '\n');
	printf("Now enter the value.\n");
	scanf("%f", &library.value);
	
	printf("%s by %s: $%.2f\n", library.title, library.author, library.value );
	printf("%s \"%s\" ($%.2f)\n", library.author, library.title, library.value );
	printf("Done!.\n");
	exit(EXIT_SUCCESS);
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
