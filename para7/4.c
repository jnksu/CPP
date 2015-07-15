#include <stdio.h>
#define MATCHP '.'
#define MATCHM '!'

int main(void)
{
	char ch;
	int count = 0;
	
	while( (ch = getchar()) != '#' )
	{
		if( ch == MATCHM ){
			printf( "!!" );
			count++;
		}
		else if( ch == MATCHP ){
			putchar(MATCHM);
			count++;
		}
		else
			putchar(ch);
	}
	printf( "%4d Times\n",count );
}