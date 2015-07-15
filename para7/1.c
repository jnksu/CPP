/*
*×Ö·ûÍ³¼Æ³ÌÐò
*/
#include <stdio.h>
#define SPACE ' '
#define ENTER '\n'

int main(void)
{
	char ch;
	int count_space,count_enter,count_other;
	
	count_space = 0;
	count_enter = 0;
	count_other = 0;
	
	printf( "Please input: " );
	
	while( ( ch = getchar() ) != '#' )
	{
		if( ch == SPACE )
			count_space++;
		ch == ENTER ? count_enter++ : count_other++;
	}
	
	printf( "has %4d space,%4d enter,%4d other",count_space,count_enter,count_other );
	
	return 0;
}