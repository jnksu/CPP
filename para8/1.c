#include <stdio.h>

int main(void)
{
	unsigned int count = 0;
	
	while(getchar() != EOF){
		count++;
	}	
	
	printf("The result is:%u\n",count);
	return 0;
}