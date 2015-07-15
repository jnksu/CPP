/* films3.c -- 使用ADT风格的链表 */
/* 和list.c一同编译 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	/* 为exit() 提供原型 */
#include "ProH.h"	// 定义List, Item

void showMovies(Item item);
void  reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	Head movies; 
	Item temp;

	/* 初始化 */
	InitializeList(&movies);
	if (ListIsFull(&movies)){
		fprintf(stderr, "No memory available! Bye!\n");
		exit(EXIT_FAILURE);
	}
	/* 收集并存储 */
	fputs("Enter first movie title: \n", stdout);
	while (fgets(temp.title, TSIZE, stdin) != NULL && temp.title[0] != '\n'){
		reject_ch(temp.title, '\n');
		
		fputs("Enter your rating<0-10>: \n", stdout);
		scanf_s("%d", &temp.rating);
		while (getchar() != '\n'){
			continue;
		}

		if (false == AddItem(temp, &movies)){
			fprintf(stderr, "Problem allocating memory\n");
			exit(EXIT_FAILURE);
		}

		if (ListIsFull(&movies)){
			fputs("The list is now full.\n", stdout);
			break;
		}
		fputs("Enter next movie title(empty line to stop): \n", stdout);
	}

	/* 显示 */
	if (ListIsEmpty(&movies))
		printf("No data entered.");
	else{
		printf("Here is the movie list: \n");
		Traverse(&movies, showMovies);
	}
	printf("You entered %d movies.\n", ListItemCount(&movies));

	/* 清除 */
	EmptyTheList(&movies);
	printf("Bye!\n");

	return EXIT_SUCCESS;
}

void showMovies(Item item)
{
	printf("Movie: %s Rating: %d\n", item.title,
		item.rating);
}

void  reject_ch(char * str, int ch)
{
	char * match;

	match = strchr(str, ch);

	if (match)
		*match = '\0';
}
