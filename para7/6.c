/*
*报告序列ei出现的次数
*/
#include <stdio.h>

int main(void)
{
	char ch;
	char prev = '#';
	int count = 0;
	
	while( (ch = getchar()) != '#' )
	{
		if( prev == 'e' && ch == 'i' )
			count++;
		prev = ch;	
	}
	printf( "Times %4d",count );
	
	return 0;
}