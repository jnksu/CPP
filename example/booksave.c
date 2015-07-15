/* booksave.c -- 把结构保存到文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL	41
#define MAXAUTL 41
#define MAXBKS	10

struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void reject_ch(char *, int);

int main(int argc, char ** argv)
{
	struct book library[MAXBKS];	/* 结构数组 */
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof(struct book);
	
	if((pbooks = fopen("book.dat", "a+b")) == NULL){
		fputs("Can't open book.dat file\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	rewind(pbooks);
	while(count < MAXBKS && fread(&library[count], size, 1, pbooks)){
		if(count == 0)
			fputs("Current contents of book.dat: \n", stdout);
		printf("%s by %s: $%.2f\n", library[count].title, 
			library[count].author, library[count].value);
		count++;
	}
	
	filecount = count;
	if(count == MAXBKS){
		fputs("The book.dat file is full.", stderr);
		exit(EXIT_FAILURE);
	}
	
	fputs("Please add new book titles.\n", stdout);
	fputs("Press [enter] at the start of a line to stop.\n", stdout);
	while(count < MAXBKS && 
		fgets(library[count].title, MAXTITL, stdin) && 
			*(library[count].title) != '\n'){
			reject_ch(library[count].title, '\n');
			fputs("Now enter the author.\n", stdout);
			fgets(library[count].author, MAXAUTL, stdin);
			reject_ch(library[count].author, '\n');
			fputs("Now enter the value.\n", stdout);
			scanf("%f", &library[count++].value);
			while(getchar() != '\n')
				continue;
	}
	
	if(count > 0){
		fputs("Here is the first of your books： \n", stdout);
		for(index = 0; index < count; index++){
			printf("%s by %s: $%.2f\n", library[index].title, 
				library[index].author, library[index].value);
		}
		fwrite(&library[filecount], size, count - filecount,
			pbooks);
	}else{
		fputs("No books? Too bad.\n", stdout);
	}
	
	fputs("Bye~!\n", stdout);
	fclose(pbooks);
	exit(EXIT_SUCCESS);
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
