/* films2.c -- 使用结构链表 */
#include <stdio.h>
#include <stdlib.h>			// 提供malloc()原型
#include <string.h>			// 提供strcpy()原型
#define TSIZE 45			// 存放片名的数组大小

struct film{
	char title[TSIZE];
	int rating;
	struct film * next;		/* 指向链表的下一个结构 */
};

typedef struct film FILM;

void reject_ch(char *, int );
int main(int argc, char ** argv)
{
	FILM * head = NULL;		// 头指针
	FILM * prev, * current;	// 指向上一个结构,指向当前结构
	char input[TSIZE];

	/* 收集并存储信息 */
	fputs("Enter first movie title: \n", stdout);
	while (fgets(input, TSIZE, stdin) && input[0] != '\n')
	{
		reject_ch(input, '\n');

		current = (FILM *)malloc(sizeof(FILM));
		if (head == NULL)	/* 第一个结构 */
			head = current;
		else				/* 后续结构 */
			prev->next = current;
		current->next = NULL;
		strcpy_s(current->title, input);
		fputs("Enter your rating<0-10>: \n", stdout);
		scanf_s("%d", &current->rating);

		while (getchar() != '\n')
			continue;

		fputs("Enter next movie title(empty line to quit): \n", stdout);
		prev = current;
	}

	/* 给出电影列表 */
	if (NULL == head)
		printf("No data enterd.\n");
	else
		printf("Here is the movie list: \n");
	current = head;
	while (current != NULL){
		printf("Movie: %s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}

	/* 任务已完成, 因此释放所分配的内存 */
	current = head;
	while (current != NULL)
	{
		prev = current->next;	//保存将要释放的节点的下一个节点
		free(current);		//释放节点
		current = prev;		//指向下一个节点
	}

	return EXIT_SUCCESS;
}

void  reject_ch(char * str, int ch)
{
	char * match;

	match = strchr(str, ch);

	if (match)
		*match = '\0';
}