/* DYN_ARC.C -- Ϊ���鶯̬����洢�ռ� */
#include <stdio.h>
#include <stdlib.h>		// Ϊmalloc()��free�����ṩԭ�� 
int main(int argc,char ** argv)
{
	double * ptd;
	int max;
	int number;
	int i = 0;
	
	fputs("What is the maximum number of type double entries?\n", stdout);
	scanf("%d", &max);
	ptd = (double *)malloc(max * sizeof(double));
	if(ptd == NULL){
		fputs("Memory allocation failed.Goodbye.\n", stdout);
		exit(EXIT_FAILURE);
	}
	/* ptd����ָ����max��Ԫ�ص����� */
	fputs("Enter the values(q for quit)\n:", stdout);
	while(i < max && scanf("%lf", &(ptd + i)) == 1)
			++i;
	printf("Here are your %d entries: \n", number = i );
	for(i = 0; i < number; i++){
		printf("7.2f", *[ptd + i]);
		if(i % 7 == 6)
			putchar('\n');
	}
	if(i % 7 != 0)
		putchar('\n');
	fputs("Done.\n", stdout);
	
	free(ptd);
	
	return 0;
}
