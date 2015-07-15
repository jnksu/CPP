#include <stdio.h>
int main(void)
{
	char ch;
	
	while((ch = getchar()) != '#')
	{
		if( ch != '\n' )
		{
			printf( "Step1\n" );
			if( ch != 'c' )
			{
				if( ch == 'b' )
					break;
				if( ch != 'g' )
					printf( "Step2 \n" );
				printf( "Step3 \n" );
			}
		}
	}
	
	printf( "Done!\n" );
	return 0;
}