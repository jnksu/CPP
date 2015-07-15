/* pe13-5.c -- 打印文件中包含给定字符的那些行 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 81

int main(int argc, char ** argv)
{
	char * line = (char *)malloc(LIM * sizeof(char));
	FILE * stream;
	
	if(argc == 3 && strlen(*(argv + 1)) == 1){
		if((stream = fopen( *(argv + 2),"r")) == NULL){
			fprintf(stderr, "Could not open %s for input.\n", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		while(fgets(line, LIM, stream)){
			if(strchr(line, **(argv + 1)))
				fputs(line, stdout);
		}
		fclose(stream);	
	}else{
		fprintf(stderr, "Usage: %s <chars> <filename>\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	free(line);
	printf("Bye!\n");
	exit(EXIT_FAILURE);
}
