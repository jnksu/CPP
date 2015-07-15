/* pe13-8.c -- 统计文件中字符出现的次数 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char ** argv)
{
	FILE * stream;
	int ch;
	unsigned long int count = 0L;
	int index;
	
	if(argc >= 2 && strlen(*(argv + 1)) == 1){
		if(argc == 2){
			while((ch = getc(stdin)) != EOF){
				if(ch == **(argv + 1))
					count++;
			}
			printf("%c:%4lu\n", **(argv  + 1), count);
		}else{
			for(index = 2; index < argc; index++){
				if((stream = fopen(*(argv + index), "r")) == NULL){
					fprintf(stderr, "Can't open file %s for input.\n", *(argv + index));
				}else if(setvbuf(stream, NULL, _IOFBF, BUFSIZE) != 0){
					fprintf(stderr, "Can't create buffer for input.\n");
				}else{
					while((ch = getc(stream)) != EOF){
						if(ch == **(argv + 1))
							count++;
					}
					printf("file %s has %c:%4lu\n", *(argv + index), **(argv + 1), count);
					count = 0L;
					fclose(stream);
				}
			}
		}
		
	}else{
		fprintf(stderr, "Usage: %s <chars> <filename1> <filename2> <...>.\n", *argv );
		exit(EXIT_SUCCESS);
	}
	
	exit(EXIT_SUCCESS);
}
