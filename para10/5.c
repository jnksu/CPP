//求出Double 数组中最大数值与最小数值的差值
#include <stdio.h>

double d_value(double * ar, int size);

int main(void)
{
	printf("The result is %.2lf",d_value((double [4]){1.1, 2.2, 3.3, 4.4}, 4));
	return 0;
}

double d_value(double * ar, int size)
{
	int max_index = 0;
	int min_index = 0;
	int count;
	
	for(count = 1; count < size; count++){
		max_index = ar[max_index] > ar[count] ? max_index : count;
		min_index = ar[min_index] < ar[count] ? min_index : count;
	}
		
	return ar[max_index] - ar[min_index];
}