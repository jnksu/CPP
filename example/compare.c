/* compare.c -- 这个程序可以满足要求 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ANSWER "GRANT"
#define MAX 40

int main(void)
{
	char  try[MAX];
	char * ch_ptr = try;
	
	puts("Who is buried in Grant's tomb?");
	gets(try);
	
	while(*ch_ptr)
	{
		*ch_ptr = toupper(*ch_ptr);
		ch_ptr++;
	}
	
	while(strcmp(try, ANSWER))
	{
		puts("No, that's wrong. Try again.");
		gets(try);
	}
	puts("That's right!");
	
	return 0;
}