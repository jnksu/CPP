/*guess.c --一个猜数程序*/
#include <stdio.h>

int main(void)
{
	int guess = 50;
	char respone;
	
	printf( "Pick an integer from 1 to 100.I will try to guess");
	printf( "it.\nRespond with a y if my guess is right and with");
	printf( "\nan n if it is wrong.\n");
	printf( "Uh...is your number %d?\n",guess);
	
	while((respone = getchar()) != 'y')
	{	
		getchar();
		if(respone == 'n')
		{
			printf("Well,then is it big?\n");
			
			while((respone = getchar()) != 'n' && respone != 'y')
			{
				printf( "I don't know What are you saying...\n");
				
				while( getchar() != '\n' )
					continue;	
			}	
			if(respone == 'n')
				printf( "Well,then,is it %d?\n",guess /= 2);
			else
				printf( "Well,then,is it %d?\n",guess = (guess + 100) / 2);
		}		
		else
			printf( "I don't know What are you saying...\n");
		
		while( getchar() != '\n' )
				continue;				
	}
	printf( "I knew I could do it!\n" );
	return 0;
}
