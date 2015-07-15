/* pe13-6.c -- 把文件压缩为原来的三分之一 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(int argc, char ** argv)
{
	FILE * in, * out;		//声明两个FILE文件指针
	int ch;
	char * name = (char *)malloc(LEN * sizeof(char));
	char * name_c = (char *)malloc(LEN * sizeof(char));
	int count = 0;
	char * match;
		
	fputs("Enter name of reduce fileName:(empty line to quit)\n", stdout);	
	while(fgets(name, LEN, stdin) && *name != '\n'){
		match = strchr(name, '\n');
		*match = '\0';
		
		if((in = fopen(name, "r")) == NULL){
			fprintf(stderr, "Can't open file %s for input\n", name);
		}else{
			match = strchr(name, '.');
			*match = '\0';
		
			strcpy(name_c, name);
			strcat(name_c, ".red");
		
			if((out = fopen(name_c, "w")) == NULL){
				fprintf(stderr, "Can't open file %s for output\n", name_c);
				if(fclose(in) != 0)
					fprintf(stderr, "Error in closing file %s\n", name);
			}
			else{
				while((ch = getc(in)) != EOF){
					if(count++ % 3 == 0){
						putc(ch, out);//打印每三个字符中的一个
					}
				}
		
			if(ferror(in) != 0)
				fprintf(stderr, "Error in reading file %s\n", name);
			if(ferror(out) != 0)
				fprintf(stderr, "Error in writing file %s\n", name_c);
			if(fclose(in) != 0 || fclose(out) != 0)
				fprintf(stderr, "Error in closing file<%s %s>\n", name, name_c);
			}
		}
		fputs("Next file (empty line quit):\n", stdout);
	}
	
	free(name);
	free(name_c);
	printf("Bye~!\n");
	exit(EXIT_SUCCESS);
}
