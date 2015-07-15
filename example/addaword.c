/* addaword.c -- 使用fprintf(), fscanf(), 和rewind()函数 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

int main(int argc, char ** argv)
{
	FILE * fp    = NULL;
	char * words = (char *)malloc(MAX * sizeof(char));
	char * judge = NULL;
	
	if((fp = fopen("wordy", "a+")) == NULL){
		fprintf(stderr, "Can't open\"words\"file.\n");
		exit(EXIT_FAILURE);
	}
	fputs( "Enter words to add to the file. Enter one word per line, and \n", stdout );
	fputs( "press the Enter key at the beginning of a line to terminate.\n", stdout );
	
	while(fgets(words, MAX, stdin)){
		judge = strchr(words, '\n');
		*judge = '\0';
		
		if(*words == '\0')
				break;
		fprintf(fp, "%s ", words);
	}
	
	fputs("File contents: \n", stdout);
	rewind(fp);/* 回到文件的开始处 */
	
	while(fscanf(fp, "%s", words) == 1){
		fputs(words, stdout);
		putc('\n', stdout);
	}
	if(fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	free(words);
	
	exit(EXIT_SUCCESS);
}
