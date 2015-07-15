/* complit.c -- 复合文字 */
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book{	//结构模版:标记是book
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(int argc, char ** argv)
{
	struct book readfrist;
	int score;
	
	printf("Enter the score: ");
	scanf("%f", &score);
	
	if(score >= 84)
		readfrist = (struct book){"Crime and punishment",
								  "Fyodor Dostoyevsky",
								  9.99};
	else
		readfrist = (struct book){"Mr. Bouncy's Nice Hat",
								  "Fred Winsomw",
								  5.99
								};
		printf("Your assigned reading:\n");
		printf("%s by %s: $%.2f\n", readfrist.title, readfrist.author, readfrist.value);
		
	exit(EXIT_SUCCESS);
}
