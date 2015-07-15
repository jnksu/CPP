/* count.c -- ʹ�ñ�׼I/O */
#include <stdio.h>
#include <stdlib.h>		//ANSI C ��exit()ԭ��

int main(int argc, char ** argv)
{
	
	int ch;			//��ȡʱ�洢ÿ���ַ���λ��
	FILE *tp;			//�ļ�ָ��
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
		putc(ch , stdout);		//�൱��putchar(ch);
		count++;
	}
	
	fclose(tp);
	printf("File %s has %ld characters\n", *(argv + 1), count);
	
	exit(EXIT_SUCCESS);
}
