#include <stdio.h>
#include <string.h>

#define MAX 81

void opOrder(char * ptr, int size);

int main(int argc, char ** argv)
{
	char temp[MAX];
	
	while(fgets(temp, MAX, stdin)){
		opOrder(temp, strlen(temp) - 1);
		fputs(temp, stdout);
	}
	
	printf("Bye!");
	return 0;
}

void opOrder(char * ptr, int size)
{
	char * temp = ptr + size - 1;
	int index;
	
	for(index = 0; index < (size / 2); index++){
		*ptr ^= *temp;
		*temp ^= *ptr;
		*ptr ^= *temp;
		
		ptr++;
		temp--;
	}
}
