/* copy3.c -- strncpy()Ê¾Àý³ÌÐò  */
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define TARGSIZE 7
#define LIM 5

int main(void)
{
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int index = 0;
	
	printf("Enter %d words beginning with q:\n", LIM);
	while(index < LIM && gets(temp))
	{
		if(temp[0] != 'q')
			printf("%s doesn't begin with q!\n", temp);
		else
		{
			strncpy(qwords[index], temp, TARGSIZE - 1);
			qwords[index][TARGSIZE - 1] = '\0';
			index++;
		}
	}
	puts("Here are the words accepted: ");
	for(index = 0; index < LIM; index++)
		puts(qwords[index]);
	
	return 0;
}