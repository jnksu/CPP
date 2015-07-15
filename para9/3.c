/*输出number行lines列的ch字符*/
#include <stdio.h>

void showch(char ch,int number,int lines);

int main(void)
{
	showch('*',4,4);
	return 0;
}

void showch(char ch,int number,int lines)
{
	int count,count_nest;
	
	for(count = 0;count < lines;count++){
		for(count_nest = 0;count_nest < number;count_nest++)
			putchar(ch);
		putchar('\n');
	}
}
