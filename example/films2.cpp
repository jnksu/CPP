/* films2.c -- ʹ�ýṹ���� */
#include <stdio.h>
#include <stdlib.h>			// �ṩmalloc()ԭ��
#include <string.h>			// �ṩstrcpy()ԭ��
#define TSIZE 45			// ���Ƭ���������С

struct film{
	char title[TSIZE];
	int rating;
	struct film * next;		/* ָ���������һ���ṹ */
};

typedef struct film FILM;

void reject_ch(char *, int );
int main(int argc, char ** argv)
{
	FILM * head = NULL;		// ͷָ��
	FILM * prev, * current;	// ָ����һ���ṹ,ָ��ǰ�ṹ
	char input[TSIZE];

	/* �ռ����洢��Ϣ */
	fputs("Enter first movie title: \n", stdout);
	while (fgets(input, TSIZE, stdin) && input[0] != '\n')
	{
		reject_ch(input, '\n');

		current = (FILM *)malloc(sizeof(FILM));
		if (head == NULL)	/* ��һ���ṹ */
			head = current;
		else				/* �����ṹ */
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

	/* ������Ӱ�б� */
	if (NULL == head)
		printf("No data enterd.\n");
	else
		printf("Here is the movie list: \n");
	current = head;
	while (current != NULL){
		printf("Movie: %s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}

	/* ���������, ����ͷ���������ڴ� */
	current = head;
	while (current != NULL)
	{
		prev = current->next;	//���潫Ҫ�ͷŵĽڵ����һ���ڵ�
		free(current);		//�ͷŽڵ�
		current = prev;		//ָ����һ���ڵ�
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