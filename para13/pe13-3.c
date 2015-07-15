/* 文件复制程序,转换文本为大写 -- pe13-3.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIM 81
#define BUFSIZE 1024

int main(int argc, char ** argv)
{
	char * sourceFileName = (char *)malloc(LIM * sizeof(char));
	char * targetFileName = (char *)malloc(LIM * sizeof(char));
	char * buffer = (char *)malloc(BUFSIZE * sizeof(char));
	FILE * source, * target;
	char * match;
	int ch;
	
	fputs("Enter name of destination file(empty line to quit): \n", stdout);
	
	while(fgets(targetFileName, LIM, stdin) && *targetFileName  != '\n'){
		match = strchr(targetFileName, '\n');
		*match = '\0';
		
		if((target = fopen(targetFileName, "w")) == NULL){
			fprintf(stderr, "Can not open %s for output.\n", targetFileName);
			exit(EXIT_FAILURE);
		}
		
		if(setvbuf(target, buffer, _IOFBF, BUFSIZE) != 0){
			fprintf(stderr, "Can't create output buffer.\n");
			exit(EXIT_FAILURE);
		}
		
		fputs("Enter name of source file(empty line to quit): \n", stdout);
		if(fgets(sourceFileName, LIM, stdin) == NULL || *sourceFileName == '\n'){
			fprintf(stdout, "Bye~!\n");
			exit(EXIT_SUCCESS);
		}
		
		match = strchr(sourceFileName, '\n');
		*match = '\0';
		
		if((source = fopen(sourceFileName, "r")) == NULL){
			fprintf(stderr, "Can not open %s for input.\n", sourceFileName);
			exit(EXIT_FAILURE);
		}
		
		if(setvbuf(source, NULL, _IOFBF, BUFSIZE) != 0){
			fprintf(stderr, "Can't create input buffer.\n");
			exit(EXIT_FAILURE);
		}
		
		while((ch = getc(source)) != EOF){
			ch = toupper(ch);
			putc(ch, target);
		}
		if(fclose(target) != 0 || fclose(source) != 0){
			fprintf(stderr, "Error in closing file.\n");
			exit(EXIT_FAILURE);
		}
		fputs("Done!.\n", stdout);
		fputs("Next file(empty line to quit):\n", stdout);
	}	
	
	free(sourceFileName);
	free(targetFileName);
	free(buffer);
	printf("Bye~!\n");
	exit(EXIT_FAILURE);
}
