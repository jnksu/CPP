/* qsorter.c -- ʹ��qsort()��һ���������� */
#include <stdio.h>
#include <stdlib.h>

#define NUM 40
void fillArray(double * ar, int size);
void showArray(double * ar, int size);
int myComp(const void * p1, const void * p2);

int main(int argc, char ** argv)
{
	double * vals = (double *)malloc(NUM * sizeof(double));
	
	fillArray(vals, NUM);
	fputs("Random list: \n", stdout);
	showArray(vals, NUM);
	qsort(vals, NUM, sizeof(double), myComp);
	fputs("\nSorted list: \n", stdout);
	showArray(vals, NUM);
	
	free(vals);
	return EXIT_SUCCESS;
}

void fillArray(double * ar, int size)
{
	int index;

	for (index = 0; index < size; index++){
		*(ar + index) = (double)rand() / ((double)rand() + 0.1);
	}
}

void showArray(double * ar, int size)
{
	int index;

	for (index = 0; index < size; index++){
		printf("%9.4f ", *(ar + index));
		if (index % 6 == 5)
			putchar('\n');
	}
	if (index % 6 != 0)
		putchar('\n');
}
/* ����С�����˳������ֵ */
int myComp(const void * p1, const void * p2)
{
	/* ��Ҫʹ��ָ��double��ָ�����ֵ*/
	const double * a1 = (const double *)p1;		//a1�Ǻ��ʵ�ָ������
	const double * a2 = (const double *)p2;

	if (*a1 < *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
}
