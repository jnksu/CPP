/* qsorter.c -- 使用qsort()对一组数字排序 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 4
#define STRLEN 31

struct name
{
	char fname[STRLEN];
	char lname[STRLEN];
};

typedef struct name NAME;

void showArray(NAME * ar, int size);
int myComp(const void * p1, const void * p2);

int main(int argc, char ** argv)
{
	NAME vals[NUM] = {
		{"Mrb", "Li"},
		{"Mra", "Li"},
		{"Oh", "no"},
		{"Oh", "aa"}
	};

	fputs("Random list: \n", stdout);
	showArray(vals, NUM);
	qsort(vals, NUM, sizeof(NAME), myComp);
	fputs("\nSorted list: \n", stdout);

	showArray(vals, NUM);

	return EXIT_SUCCESS;
}

void showArray(NAME * ar, int size)
{
	int index;
	int count = 0;

	for (index = 0; index < size; index++){
		printf("%s %s\n", (ar + index)->fname, (ar + index)->lname);
	}
}

/* 按从小到大的顺序排序值 */
int myComp(const void * p1, const void * p2)
{
	/* 需要使用指向double的指针访问值*/
	const NAME * a1 = (const NAME *)p1;		//a1是合适的指针类型
	const NAME * a2 = (const NAME *)p2;
	int res;

	res = strcmp(a1->fname, a2->fname);
	if (res != 0)
		return res;
	else
		return strcmp(a1->lname, a2->lname);
}
