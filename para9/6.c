/*求出每个字母的位置(不区分大小写)*/
#include <stdio.h>

int position(char ch);

int main(void)
{
	int ch;
	int status;
	
	while((ch = getchar()) != EOF ){
		if( (status = position(ch)) != -1 )
			printf("The letter %c in table position is %d\n",ch,status + 1);
		else
			printf( "The char %c is not a letter\n",ch);
	}
	
	return 0;
}

int position(char ch)
{
	if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') )
		return ch >= 'a' ? (ch -= 'a') : (ch -= 'A');
	return -1;
}