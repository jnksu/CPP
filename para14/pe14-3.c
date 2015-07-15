/* pe14-3.c -- 包含多本书的图书目录 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41		//标题最多字数
#define MAXAUTL 41		//作者最多字数
#define MAXBKS 100		//最多可以容纳的图书册数

typedef struct {		//建立BOOK模版
	char  title[MAXTITL];
	char  author[MAXAUTL];
	float value;
} BOOK;

void show_title_ASC(BOOK ** bkptr, int size);
void show_value_ASC(BOOK ** bkptr, int size);
void copy_arrp(BOOK ** tbkptr, BOOK * sbkptr, int size);
void show_normal(BOOK * bkptr, int size);
void show_pn(BOOK ** bkptr, int size);
void reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	BOOK library[MAXBKS];
	int count = 0;
	
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	
	while(count < MAXBKS && fgets(library[count].title, MAXTITL, stdin)
			&& library[count].title[0] != '\n')
	{
		reject_ch(library[count].title, '\n');
		
		printf("Now enter the author.\n");
		fgets(library[count].author, MAXAUTL, stdin);	
		reject_ch(library[count].author, '\n');
		
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		
		while(getchar() != '\n')
			continue;
		if(count < MAXBKS)
			printf("Enter the next title.\n");
	}
	if(count > 0){
		show_normal(library, count);
		
		BOOK * library_dup[count];
		copy_arrp(library_dup, library, count);
		
		show_title_ASC(library_dup, count);
		show_value_ASC(library_dup, count);
	}else{
		printf("No books?Too bad.\n");
	}
	
	exit(EXIT_SUCCESS);
}
//按照升序对书本标题排序
void show_title_ASC(BOOK ** bkptr, int size)
{
	int index;
	int indexNest;
	BOOK * tpr;
	
	for(index = 0; index < size - 1; index++)
		for(indexNest = index + 1; indexNest < size; indexNest++){
			if(strcmp((**(bkptr + index)).title, (**(bkptr + indexNest)).title) > 0){
				tpr = *(bkptr + index);
				*(bkptr + index) = *(bkptr + indexNest);
				*(bkptr + indexNest) = tpr;
			}
		}
	show_pn(bkptr, size);
}
//按照升序对书本价格排序
void show_value_ASC(BOOK ** bkptr, int size)
{
	int index;
	int indexNest;
	BOOK * tpr;
	
	for(index = 0; index < size - 1; index++ )
		for(indexNest = index + 1; indexNest < size; indexNest++){
			if((**(bkptr + index)).value > (**(bkptr + indexNest)).value){
				tpr = *(bkptr + index);
				*(bkptr + index) = *(bkptr + indexNest);
				*(bkptr + indexNest) = tpr;
			}
		}
	show_pn(bkptr, size);
}
//给图书指针数组赋值
void copy_arrp(BOOK ** tbkptr, BOOK * sbkptr, int size)
{
	int index;
	
	for(index = 0; index < size; index++)
		*(tbkptr + index) = (sbkptr + index);
}
//显示存储的图书
void show_normal(BOOK * bkptr, int size)
{
	int index;
	
	printf("Here is the list of your books: \n");
	for(index = 0; index < size; index++)
		printf("%s by %s: $%.2f\n", (*(bkptr + index)).title,
			(*(bkptr + index)).author, (*(bkptr + index)).value);
	
}
//通过二级指针显示存储的图书
void show_pn(BOOK ** bkptr, int size)
{
	int index;
	
	printf("Here is the list of your books: \n");
		for(index = 0; index < size; index++)
			printf("%s by %s: $%.2f\n", (**(bkptr + index)).title,
				(**(bkptr + index)).author, (**(bkptr + index)).value);
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
