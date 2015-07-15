/*  book.c -- 仅包含一本书的图书目录 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 41 /* 书名的最大长度+1 */
#define MAXAUTL 31 /* 作者名的最大长度+1 */

void reject_ch(char *, int);
struct book{	   /* 作者结构模版:标记为book */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};				   /* 结构模版结束 */

int main(int argc, char ** argv)
{
	struct book library; /* 把library声明为book类型的变量 */
	printf("Please enter the book title.\n");
	fgets(library.title, MAXTITL, stdin); /* 访问title 部分 */
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
