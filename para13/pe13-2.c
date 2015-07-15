/* 一个文件复制程序,使用命令行参数 -- pe13-2.c */
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 419430400

int main(int argc, char ** argv)
{
	FILE * tp;
	FILE * sp;
	char * buffer = (char *)malloc(BUFSIZE * sizeof(char));
	char * cache = (char *)malloc(BUFSIZE * sizeof(char));
	size_t bytes;
	
	if(argc == 3){
		if((tp = fopen(*(argv + 1), "wb")) == NULL){
			fprintf(stderr, "Could not open %s for output.\n", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		if(setvbuf(tp, buffer, _IOFBF, BUFSIZE)){
			fputs( "Can't create output buffer",stderr);
			exit(EXIT_FAILURE);
		}
		if((sp = fopen(*(argv + 2), "rb")) == NULL){
			fprintf(stderr, "Could not open %s for input.\n", *(argv + 2));
			exit(EXIT_FAILURE);
		}		
		if(setvbuf(sp, NULL, _IOFBF, BUFSIZE)){
			fputs("Can't create input buffer", stderr);
			exit(EXIT_FAILURE);
		}
		
		while((bytes = fread(cache, sizeof(char), BUFSIZE, sp)) > 0){
			fwrite(cache, sizeof(char), bytes, tp);
			printf("%d bytes has copy!\n", bytes);
		}
		
	}else{
		fprintf(stderr, "Usage: %s <targetFileName> <sourceFileName>\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	if(fclose(tp) != 0 || fclose(sp) != 0){
		fprintf(stderr, "Error in closing files\n");
		exit(EXIT_FAILURE);
	}
	else{
		free(buffer);
		free(cache);
		printf("Done!\n");
	}
	exit(EXIT_SUCCESS);
}
