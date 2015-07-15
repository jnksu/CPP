/* reverse.c -- 反序显示一个文件 */
#include <stdio.h>
#include <stdlib.h>

#define CNTL_Z '\032'		/* DOS文本文件中的文件结尾标记 */
#define SLEN 50

int main(int argc, char ** argv)
{
	char * file = (char *)malloc(SLEN * sizeof(char));
	char ch;
	FILE * fp;
	long int count, last;
	
	fputs("Enter the name of the file to be processed: ", stdout);
	fscanf(stdin, "%s", file);
	
	/* 只读和二进制模式 */
	if((fp = fopen(file, "rb")) == NULL){
		fprintf(stderr, "reverse can't open %s\n", file);
		exit(EXIT_FAILURE);
	}
	
	fseek(fp, 0L, SEEK_END);		/* 定位到文件结尾处 */
	
	last = ftell(fp);
	for(count = 1L; count <= last; count++){
		fseek(fp, -count, SEEK_END);/* 回退             */
		ch = getc(fp);
	/* 针对DOS,在UNIX下也可工作 */
		if(ch != CNTL_Z && ch != '\r')
			putchar(ch);
	/* 针对Macintosh            */
	/*	if(ch == '\r')
			putchar('\n');
		else
			putchar(ch);		*/
	}
	putchar('\n');
	
	fclose(fp);
	free(file);
	
	exit(EXIT_SUCCESS);
}
