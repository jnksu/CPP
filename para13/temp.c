/* 读取图片数据并显示图片和存储图片 -- pe13-12.c */
#include <stdio.h>
#include <stdlib.h>
#define LEVELS 10
#define COLS 31
#define ROWS 20

int main(int argc, char ** argv)
{
	const char * match_str = " .':~*=&%@";
	char (* pic)[COLS]     = (char (*)[COLS])calloc(ROWS * COLS, sizeof(char));
	char (* pic_num)[COLS]  = (char  (*)[COLS])calloc(ROWS *(COLS - 1), sizeof(char)); 
	FILE * in, * out;
	int index, indexNest;
	int match_exc = 0;
	
	if(argc == 3){
		if((in = fopen(*(argv + 2), "r")) == NULL){
			fprintf(stderr, "can not open file %s.\n", *(argv + 2));
			exit(EXIT_FAILURE);
		}
		
		if((out = fopen(*(argv + 1), "w")) == NULL){
			fprintf(stderr, "Can not open file %s.\n", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		
		for(index = 0; index < ROWS; index++)
			for(indexNest = 0; indexNest < COLS - 1; indexNest++){
				fscanf(in, "%d", &match_exc);
				*(*(pic_num + index) + indexNest) = (char)match_exc;
			}
		
		for(index = 0; index < ROWS; index++){
			for(indexNest = 0; indexNest < COLS - 1; indexNest++){
				fprintf(stdout, "%c " ,*(match_str + *(*(pic_num + index) + indexNest)));
			}
			putchar('\n');
		}
		if(fclose(in) != 0){
			fprintf(stderr, "Error in closing %s", *(argv + 2));
			exit(EXIT_FAILURE);
		}
		
		for(index = 0; index < ROWS; index++){
			fprintf(stdout, "%s\n", *(pic + index));
			fprintf(out, "%s\n", *(pic + index));
		}
		
		if(fclose(out) != 0){
			fprintf(stderr, "Error in closing %s", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		
	}else{
		fprintf(stderr,"Usage: %s [targetFileName] [SourceFileName].\n", *argv );
		exit(EXIT_FAILURE);
	}
	
	free(pic);
	free(pic_num);
	printf("Bye~!\n");
	exit(EXIT_SUCCESS);
}
