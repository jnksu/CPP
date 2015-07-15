/*guess.c --一个猜数程序*/
#include <stdio.h>
int main(void)
{
	int guess = 1;
	char respone;
	
	printf( "Pick an integer from 1 to 100.I will try to guess");
	printf( "it.\nRespond with a y if my guess is right and with");
	printf( "\nan n if it is wrong.\n");
	printf( "Uh...is your number %d?\n",guess);
	
	while((respone = getchar()) != 'y'){
		if(respone == 'n')
			printf( "Well,then,is it %d?\n",++guess);
		else
			printf( "I don't know What are you saying...\n");
		
		while( getchar() != '\n' )
				continue;				
	}
	printf( "I knew I could do it!\n" );
	return 0;
}
