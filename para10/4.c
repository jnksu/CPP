//返回double数组最大值索引
#include <stdio.h>

int max_index(double * ar, int size);

int main(void)
{
	printf("The result is %d", max_index((double [5]){1.0, 345.0, 454.0, 5.0, 57.0}, 5));
	return 0;
}

int max_index(double * ar, int size)
{
	int count;
	int max_index = 0;
	
	for(count = 1; count < size; count++)
		max_index = ar[max_index] > ar[count] ? max_index : count;
	
	return max_index;
}