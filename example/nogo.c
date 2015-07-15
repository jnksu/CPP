/* nogo.c -- 这个程序能满足要求吗？ */
#include  <stdio.h>
#include <string.h>
#define ANSWER "Grant"

int main(void)
{
	char try[40];
	
	puts("Who is buried in Gran's tomb");
	gets(try);
	while(strcmp(try, ANSWER))
	{
		puts("No,that's wrong. Try again.");
		gets(try);
	}
	puts("That's right!");
	
	return 0;
}