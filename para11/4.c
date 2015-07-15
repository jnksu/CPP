#include <stdio.h>
#define MAX 81

char * cpch(char * ptr, int ch);

int main(int argc, char ** argv)
{
	char temp[MAX];
	
	while(fgets(temp,MAX,stdin)){
		putchar(*cpch(temp, 'z'));
	}
	
	printf("Bye!");
	return 0;
}

char * cpch(char * ptr, int ch)
{
	while(*ptr){
		if(*ptr == ch)
			return ptr;
		else
			ptr++;
	}
	return NULL;
}
