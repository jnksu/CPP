/* flexmemb.c -- 伸缩型数组成员 */
#include <stdio.h>
#include <stdlib.h>

struct flex{
	int count;
	double average;
	double score[];	//伸缩型素组成员
};

void showFlex(const struct flex * p);

int main(int argc, char ** argv)
{
	struct flex * pf1, * pf2;
	int n = 5;
	int i;
	int tot = 0;
	
	//为结构和数组分配存储空间
	pf1 = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(double));
	pf1 -> count = n;
	for(i = 0; i < n; i++)
	{
		pf1 -> score[i] = 20.00 - i;
		tot += pf1 -> score[i];
	}
	pf1 -> average = tot / n;
	showFlex(pf1);
	
	n = 9;
	tot = 0;
	
	pf2 = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(double));
	pf2 -> count = n;
	for(i = 0; i < n; i++){
		pf2 -> score[i] = 20.0 - i / 2.0;
		tot += pf2 -> score[i];
	}
	pf2 -> average = tot / n;
	showFlex(pf2);
	free(pf1);
	free(pf2);
	
	exit(EXIT_SUCCESS);
}

void showFlex(const struct flex * p)
{
	int i;
	printf("Scores: \n");
	for(i = 0; i < p->count; i++)
		printf("%g ", p->score[i]);
	printf("\nAverage: %g\n", p->average);
}
