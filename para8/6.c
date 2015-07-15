#include <ctype.h>
#include <stdio.h>
char get_first(void);

int main(void)
{
	putchar(get_first());
	return 0;
}

char get_first(void)
{
	char ch;
	
	while( isspace( ch = getchar() ))
		continue;
	while( getchar() != '\n' )		//Çå¿Õ»º´æÇø
		continue;
	return ch;
}