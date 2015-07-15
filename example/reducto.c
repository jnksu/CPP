// reducto.c -- ������ļ�ѹ��Ϊԭ��������֮һ!
#include <stdio.h>
#include <stdlib.h>		//Ϊ�˵���exit()
#include <string.h>		//Ϊstrcpy()��strcat()�����ṩԭ��
#define LEN 40

int main(int argc, char ** argv)
{
	FILE * in, * out;	//��������FILEָ��
	int ch;
	char * name = (char *)malloc(LEN * sizeof(char));
	int count = 0;
	
	//��������в��� 
	if(argc < 2){
		fprintf(stderr, "Usage: %s filename\n", *argv);
		exit(EXIT_FAILURE);
	}
	//ʵ������
	if((in = fopen(*(argv + 1), "r")) == NULL){
		fprintf(stderr, "I couldn't open the file\"%s\"\n",
					*(argv + 1));
		exit(EXIT_FAILURE);
	}
	//ʵ�����
	strcpy(name, *(argv + 1));		//���ļ������Ƶ�������
	strcat(name, ".red");			//���ļ��������.red
	if((out = fopen(name, "w")) == NULL){
		//���ļ��Թ�д��
		fprintf(stderr, "Can't create output file.\n");
		exit(EXIT_FAILURE);
	}
	//��������
	while((ch = getc(in)) != EOF){
		if(count++ % 3 == 0)
			putc(ch, out);			//��ӡÿ3���ַ��е�1��
	}
	
	//��β����
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");
	free(name);
	
	exit(EXIT_SUCCESS);
}
