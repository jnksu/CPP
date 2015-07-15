/* pe13-5.c -- 把多个文件追加到一个文件中 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81

void append(FILE * source, FILE * dest);

int main(int argc, char ** argv)
{
	FILE * fa, * fs;		//fa指向追加的目的文件, fs 指向源文件
	int files = 0;			//追加的文件个数
	int index;
	
	if(argc >= 3){
		if((fa = fopen(*(argv + 1), "ab")) == NULL){
			fprintf(stderr, "Could not open file %s for output.\n", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0){
			fputs("Can't create output buffer.\n", stderr);
			exit(EXIT_FAILURE);
		}
		
		for(index = 2; index < argc; index++)
		{
			if(strcmp(*(argv + 1), *(argv + index)) == 0){
				fputs("Can't append file to itself.\n", stderr);
			}else if((fs = fopen(*(argv + index), "rb")) == NULL){
					fprintf(stderr, "Can't open file %s for input.\n", *(argv + index));
			}else{
				if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0){
					fputs("Can't create input buffer\n", stderr);
					continue;
				}
				append(fs, fa);
				if(ferror(fs) != 0)
					fprintf(stderr, "Error in reading file %s.\n", *(argv + index));
				if(ferror(fa) != 0)
					fprintf(stderr, "Error in writing file %s.\n", *(argv + 1));
				fclose(fs);
				files++;
				printf("File %s append.\n", *(argv + index));
			}
		}		
	}else{
		fprintf(stderr, "Usage: %s <targetFileName> <sourceFileName1> <sourceFileName2> ...\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	printf("Done. %d files append.\n", files);
	fclose(fa);
	exit(EXIT_SUCCESS);
}

void append(FILE * source, FILE * dest)
{
	static char buffer[BUFSIZE];
	size_t bytes;
	
	while((bytes = fread(buffer, sizeof(char), BUFSIZE, source)) > 0){
		fwrite(buffer, sizeof(char), bytes, dest);
	}
}
