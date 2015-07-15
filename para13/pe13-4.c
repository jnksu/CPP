/* 显示命令行中列出的全部文件 -- pe13-4.c */
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024

int main(int argc, char ** argv)
{
	FILE * fp;
	int i;
	int ch;
	
	if(argc > 1){
	
		for(i = 1; i < argc; i++){
			if((fp = fopen(*(argv + i), "r")) == NULL){
				fprintf(stderr, "Can not open file %s for input\n", *(argv + i));
			}else{
				if(setvbuf(fp, NULL, _IOFBF, BUFSIZE) != 0){
					fprintf(stderr, "can't create buffer for input.\n");
					exit(EXIT_FAILURE);
				}
				fprintf(stdout, "%s\n", *(argv + i));
				while((ch = getc(fp)) != EOF){
					putc(ch, stdout);
				}
				putc('\n', stdout);
				if(fclose(fp) != 0){
				fprintf(stderr, "Error in closing file.\n");
				exit(EXIT_FAILURE);
				}
			}
		}
	}else{
		printf("No file used!\n");
		exit(EXIT_SUCCESS);
	}
	
	printf("Bye~!\n");
	exit(EXIT_SUCCESS);
}
