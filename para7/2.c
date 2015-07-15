/*
*×Ö·û´¦Àí³ÌÐò
*/
#include <stdio.h>
#define SPACE ' '
#define ENTER '\n'

int main(void)
{
	char ch;
	int count = 1;
	
	printf( "Please input\n:" );
	
	while( (ch = getchar()) != '#' )
	{	
		printf( "%4d\t",ch );
		
		if( ch != SPACE && ch != ENTER )
			putchar(ch);
		else
			printf( "%s",ch == SPACE ? "S" : "E" );
		
		if( (count++ % 8) == 0 )
			printf( "\n" );
	}
}