/* pe13-1.c -- 输出用户请求的文件,并计算字符个数 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIM 81

int main(int argc, char ** argv)
{
	int ch;
	FILE * tp;
	long int count = 0;
	char * filename = (char *)malloc(LIM * sizeof(char));
	char * match;
	
	fputs("Enter name of first file(empty line to quit):\n", stdout);
	while(fgets(filename, LIM, stdin) && *filename != '\n'){
		match = strchr(filename, '\n');
		*match = '\0';
		
		if((tp = fopen( filename,"r")) == NULL){
			fprintf(stderr, "Could not open %s for output.\n", filename);
			exit(EXIT_FAILURE);
		}
		
		while((ch = getc(tp)) != EOF){
			putc(ch, stdout);
			count++;
		}	
		
		fclose(tp);
		printf("File %s has %ld characters\n", filename, count);
		fputs("Next file(empty line to quit):\n", stdout);
	}
	
	free(filename);
	printf("Bye!\n");
	exit(EXIT_SUCCESS);
}
