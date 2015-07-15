/* append.c -- 把多个文件的内容追加到一个文件中 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81

void append(FILE * source, FILE * dest, char * buffer);
void get_str(char * fill, int size);

int main(int argc, char ** argv)
{
	FILE * fa, * fs;										//fa指向追加的目的文件, fs指向源文件
	int file = 0;											//追加的文件个数
	char * file_app = (char *)malloc(SLEN * sizeof(char));	//被追加文件的名称
	char * file_src = (char *)malloc(SLEN * sizeof(char));	//源文件的名称
	char * buffer = (char *)malloc(BUFSIZE * sizeof(char)); //数据缓冲区
	
	printf("Enter name of destination file: ");
	
	get_str(file_app, SLEN);
	if((fa = fopen(file_app, "a")) == NULL){
		fprintf(stderr, "Can't open %s \n", file_app);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(fa, NULL, _IOFBF, BUFSIZE)){
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter the name of first source file(empty to quit):\n");
	get_str(file_src, SLEN);
	while(*file_src != '\0'){
		if(!strcmp(file_app, file_src)){
			fputs("Can't append file to itself\n", stderr);
		}else if((fs = fopen(file_src, "r")) == NULL){
			fprintf(stderr, "can't open %s\n", file_src);
		}else{
			if(setvbuf(fs, NULL, _IOFBF, BUFSIZE)){
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa, buffer);
			if(ferror(fs))
				fprintf(stderr, "Error in reading file %s\n", file_src);
			if(ferror(fa))
				fprintf(stderr, "Error in reading file %s\n", file_app);
			fclose(fs);
			file++;
			printf("File %s append.\n", file_src);
			fputs("Next file(empty to quit)\n", stdout);
			get_str(file_src, SLEN);
		}
	}
	
	printf("Done. %d files append.\n", file);
	fclose(fa);
	free(file_app);
	free(file_src);
	free(buffer);
	exit(EXIT_SUCCESS);
}

void append(FILE * source, FILE * dest, char * buffer)
{
	size_t bytes;
	
	while((bytes = fread(buffer, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(buffer, sizeof(char), bytes, dest);
}

void get_str(char * fill, int size)
{
	char * match;
	
	while(!fgets(fill, size, stdin) && *fill == '\n'){
		fprintf(stderr , "Please input correct file name!\n:");
	}
	
	match = strchr(fill, '\n');
	*match = '\0';
}
