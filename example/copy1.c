/* copy1.c -- strcpy() Ê¾Àý³ÌÐò */
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIM 5

int main(void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int index = 0;
	
	printf("Enter %d words beginning with q:\n", LIM);
	while(index < LIM && gets(temp))
	{
		if(temp[0] != 'q')
			printf("%s doesn't begin with q!\n", temp);
		else
		{
			strcpy(qwords[index],temp);
			index++;
		}
	}
	puts("Here are the words accepted: ");
	for(index = 0; index < LIM; index++)
		puts(qwords[index]);
	
	return 0;
}
