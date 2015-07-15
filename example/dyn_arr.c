/* DYN_ARC.C -- 为数组动态分配存储空间 */
#include <stdio.h>
#include <stdlib.h>		// 为malloc()和free函数提供原型 
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
	/* ptd现在指向有max个元素的数组 */
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
