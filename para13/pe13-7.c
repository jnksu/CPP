/* pe13-7 -- Êä³öÎÄ¼þ*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81

int main(int argc, char ** argv)
{
	FILE * fp, * fp1;
	char * str = (char *)malloc(SLEN * sizeof(char));
	char * str1 = (char *)malloc(SLEN * sizeof(char));
	char * match, * match1;
	
	if(argc == 3){
		if((fp = fopen(*(argv + 1), "r")) == NULL){
			fprintf(stderr, "Can not open file %s for input.\n", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		if((fp1 = fopen(*(argv + 2), "r")) == NULL){
			fprintf(stderr, "Can not open file %s for input.\n", *(argv + 2));
			exit(EXIT_FAILURE);
		}
		
		while(( match = fgets(str, SLEN, fp)) && (match1 = fgets(str1, SLEN, fp1))){
			fputs(str, stdout);
			fputs(str1, stdout);
		}
		
		if(match){
			while(fgets(str, SLEN, fp))
				fputs(str, stdout);
		}
		
		if(match1){
			while(fgets(str1, SLEN, fp1))
				fputs(str1, stdout);
		}
		
		if(ferror(fp) != 0)
			fprintf(stderr, "Error in reading file %s.\n", str);
		if(ferror(fp1) != 0)
			fprintf(stderr, "Error in reading file %s.\n", str1);
		
		if(fclose(fp) != 0 || fclose(fp1) != 0){
			fprintf(stderr, "Error in closing file.\n");
			exit(EXIT_FAILURE);
		}
	}else{
		fprintf(stderr, "Usage: %s <FileName1> <FileName2>\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	free(str);
	free(str1);
	exit(EXIT_SUCCESS);
}
