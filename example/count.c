/* count.c -- 使用标准I/O */
#include <stdio.h>
#include <stdlib.h>		//ANSI C 的exit()原型

int main(int argc, char ** argv)
{
	
	int ch;			//读取时存储每个字符的位置
	FILE *tp;			//文件指针
	long int count = 0;
	
	if(argc != 2){
		fprintf(stderr, "Usage: %s filename\n", *argv);
		exit(EXIT_FAILURE);
	}
	if((tp = fopen(*(argv + 1), "r")) == NULL){
		fprintf(stderr, "can't open %s\n", *(argv + 1));
		exit(EXIT_FAILURE);
	}
	while((ch = getc(tp)) != EOF){
		putc(ch , stdout);		//相当于putchar(ch);
		count++;
	}
	
	fclose(tp);
	printf("File %s has %ld characters\n", *(argv + 1), count);
	
	exit(EXIT_SUCCESS);
}
