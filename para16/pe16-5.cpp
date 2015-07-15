/* pe16.5.c -- һ��������� */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 51
#define PICKS 6

void random(int *, int, int);
int rollem(int);
bool isMatch(int *, int, int);

int main(int argc, char ** argv)
{
	int lotto[LEN];
	int i;
	char ch;
	srand((unsigned int)time(NULL));		//��ʼ������
	for (i = 0; i < LEN; i++)
		lotto[i] = i + 1;

	do {
		random(lotto, LEN, PICKS);
		printf("Again? <y/n> ");
		ch = getchar();
		while (getchar() != '\n')
			continue;
	} while (ch == 'y' || ch == 'Y');

	puts("Done");

	return EXIT_SUCCESS;
}

void random(int * arr, int size, int choice)
{
	int * use = (int *)calloc(choice, sizeof(int));


	for (int index = 0; index < choice; index++){

		//���������Ѿ�����	
		while (isMatch(use, index,  (*(use + index) = rollem(size))) ){
			continue;
		}
	}

	int count = 0;
	for (int index = 0; index < choice; index++){
		printf("%d ", *(arr + *(use + index)));

		if (0 == ++count % LEN && count != choice)
			putchar('\n');
	}

	free(use);
}

int rollem(int size)
{
	int roll;

	roll = rand() % size;

	return roll;
}
//����ƥ��
bool isMatch(int * arr, int size, int match)
{
	for (int index = 0; index < size; index++){
		if (match == *(arr + index))
			return true;
	}

	return false;
}
