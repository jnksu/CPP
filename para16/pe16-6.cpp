/* qsorter.c -- ʹ��qsort()��һ���������� */
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

/* ����С�����˳������ֵ */
int myComp(const void * p1, const void * p2)
{
	/* ��Ҫʹ��ָ��double��ָ�����ֵ*/
	const NAME * a1 = (const NAME *)p1;		//a1�Ǻ��ʵ�ָ������
	const NAME * a2 = (const NAME *)p2;
	int res;

	res = strcmp(a1->fname, a2->fname);
	if (res != 0)
		return res;
	else
		return strcmp(a1->lname, a2->lname);
}
