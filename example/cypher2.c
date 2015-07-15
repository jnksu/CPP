/*
 * cypher2.c
 *
 *  Created on: 2013-12-27
 *      Author: Mr_Li
 */

#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;

	while( (ch = getchar()) != '\n')
	{
		if( isalpha( ch ))
			putchar( ch + 1 );
		else
			putchar( ch );
	}
	putchar( ch );
	return 0;
}
