/* parrot.c -- ʹ��fgets()��fputs()���� */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 20

int main(int argc, char ** argv)
{
	char * line = (char *)malloc(MAXLINE * sizeof(char));
	
	while(fgets(line, MAXLINE, stdin) && *line != '\n')
			fputs(line, stdout);
			
	exit(EXIT_SUCCESS);
}
