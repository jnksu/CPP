/* pe13-11.c -- 匹配文件中相同字符串的行 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81


static void rejectch(char * str, int ch);

int main(int argc, char ** argv)
{
	FILE * fp;
	char * filename = (char *)malloc(SLEN * sizeof(char));
	char * line = (char *)malloc(SLEN * sizeof(char));
	char * matchline = (char *)malloc(SLEN * sizeof(char));
	
	fputs("Enter name of file(empty line to quit):\n", stdout);
	while(fgets(filename, SLEN, stdin) && *filename != '\n'){
		rejectch(filename, '\n');
		
		if((fp = fopen(filename, "r")) == NULL){
			fprintf(stderr, "Can not open %s\n", filename);
		}else{
			
			fputs("Enter the string you want match(empty line to quit).\n", stdout);
			while(fgets(line, SLEN, stdin) && *line != '\n'){
				rejectch(line, '\n');
				
				while(fgets(matchline, SLEN, fp)){
					if(strstr(matchline, line))
						fputs(matchline, stdout);	
				}
				
				rewind(fp);
				fputs("Next string(empty line to quit).\n", stdout);
			}
			
			if(fclose(fp) != 0){
				fprintf(stderr, "Error in closing %s\n", filename);
				exit(EXIT_FAILURE);
			}
		}
		
		fputs("Next file(empty line to quit):\n", stdout);
	}
	
	free(filename);
	free(line);
	free(matchline);
	printf("Bye!~");
	exit(EXIT_SUCCESS);
}

static void rejectch(char * str, int ch){
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
