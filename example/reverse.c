/* reverse.c -- ������ʾһ���ļ� */
#include <stdio.h>
#include <stdlib.h>

#define CNTL_Z '\032'		/* DOS�ı��ļ��е��ļ���β��� */
#define SLEN 50

int main(int argc, char ** argv)
{
	char * file = (char *)malloc(SLEN * sizeof(char));
	char ch;
	FILE * fp;
	long int count, last;
	
	fputs("Enter the name of the file to be processed: ", stdout);
	fscanf(stdin, "%s", file);
	
	/* ֻ���Ͷ�����ģʽ */
	if((fp = fopen(file, "rb")) == NULL){
		fprintf(stderr, "reverse can't open %s\n", file);
		exit(EXIT_FAILURE);
	}
	
	fseek(fp, 0L, SEEK_END);		/* ��λ���ļ���β�� */
	
	last = ftell(fp);
	for(count = 1L; count <= last; count++){
		fseek(fp, -count, SEEK_END);/* ����             */
		ch = getc(fp);
	/* ���DOS,��UNIX��Ҳ�ɹ��� */
		if(ch != CNTL_Z && ch != '\r')
			putchar(ch);
	/* ���Macintosh            */
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
