/* films1.c -- 使用结构数组 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TSIZE 45 /* 存放片名的数组大小 */
#define FMAX 5   /* 最多的影片数 */

struct film
{
	char title[TSIZE];
	int rating;
};

typedef struct film FILM;
void  reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	FILM movies[FMAX];
	int index = 0;
	int indexNest;

	fputs("Enter the first movie title: \n", stdout);
	while (index < FMAX && fgets(movies[index].title, TSIZE, stdin) != NULL &&
			movies[index].title[0] != '\n'){
		reject_ch(movies[index].title, '\n');
		fputs("Enter your rating <0-10>: \n", stdout);
		scanf_s("%d", &movies[index++].rating);

		while (getchar() != '\n')
			continue;
		fputs("Enter next movie title (empty line to stop): \n", stdout);
	}

	if (index == 0)
		printf("No data entered. ");
	else
		printf("Here is the movie list: \n");

	for (indexNest = 0; indexNest < index; indexNest++)
		printf("Movie: %s Rating: %d\n", movies[indexNest].title,
				movies[indexNest].rating);
	printf("Bye!\n");

	return EXIT_SUCCESS;
}

void  reject_ch(char * str, int ch)
{
	char * match;

	match = strchr(str, ch);

	if (match)
		*match = '\0';
}