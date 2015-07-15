#include <stdio.h>
#include <stdbool.h>
#define MAX 81

bool is_within(const char * ptr, int ch);

int main(int argc, char ** argv)
{
	char temp[MAX];
	
	while(fgets(temp,MAX,stdin)){
		if(is_within(temp, 'z'))
			printf("true\n");
		else
			printf("false\n");
	}
	
	printf("Bye!");
	return 0;
}

bool is_within(const char * ptr, int ch)
{
	while(*ptr){
		if(*ptr == ch)
			return true;
		else
			ptr++;
	}
	return false;
}