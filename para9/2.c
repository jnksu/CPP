/*在指定的列输出相应的字符*/
#include <stdio.h>

void chline(char ch,int begin,int end);

int main(void)
{
	chline('@',7,45);
	return 0;
}

void chline(char ch,int begin,int end)
{
	int count;
	for( count = 1;count < begin;count++ )
		putchar(' ');
	for( count = begin;count <= end;count++ )
		putchar( ch );
	putchar('\n');	
}