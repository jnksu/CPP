#include <stdio.h>
#define MAX 81

char * strncpy_c(char * target, char * source, int size);

int main(int argc, char ** argv)
{
	char temp[MAX];
	char temp1[MAX];
	
	while(fgets(temp, MAX, stdin)){
		strncpy_c(temp1, temp, 10);
		fputs(temp1, stdout);
	}
	
	printf("Bye!");
	return 0;
}

char * strncpy_c(char * target, char * source, int size)
{
	int index;
	
	for(index = 0; index < size; index++)
		*target++ = (*source == '\0' ? ' ' : *source++);
	*target = '\0';
	
	return target;
}