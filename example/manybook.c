/* manybook.c -- 包含多本书图书目录 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100 /* 最多可以容纳的图书册数 */

void reject_ch(char *, int);

struct book{		/* 建立book模版           */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(int argc, char ** argv)
{
	struct book library[MAXBKS]; /* book结构数组 */
	int count = 0;
	int index;
	
	printf("please enter the book title.\n");
	printf("Press [enter] at the start if a line to stop.\n");
	while(count < MAXBKS && 
		fgets(library[count].title, MAXTITL, stdin) && 
		library[count].title[0] != '\n'){
		
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
		printf("Here is the list of you books: \n");
		for(index = 0; index < count; index++)
			printf("%s by %s: %.2f\n", library[index].title, 
				library[index].author, library[index].value);
	}else{
		printf("No books? Too bad.\n");
	}
	
	exit(EXIT_SUCCESS);
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
