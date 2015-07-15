/*
 * cypher1.c
 *
 *  Created on: 2013-12-27
 *      Author: Mr_Li
 */
#include <stdio.h>
#define SPACE ' '

int main(void)
{
	char ch;

	ch = getchar();
	while( ch != '\n' )
	{
		if( ch == SPACE )
			putchar( ch );
		else
			putchar( ch + 1 );
		ch = getchar();
	}
	putchar( ch );
	return 0;
}

