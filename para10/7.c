// 复制数组
#include <stdio.h>	

void copy_arr(const double source[], double target[], int size);
void copy_ptr(const double * source, double * target, int size);

int main(void)
{
	double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	double target1[3];
	
	copy_arr(&source[2], target1, 3);
	
	return 0;
}

void copy_arr(const double source[], double target[], int size)
{
	int count;
	for(count = 0; count < size; count++)
		target[count] = source[count];
}

void copy_ptr(const double * source, double * target, int size)
{
	int count;									`										
	for(count = 0; count < size; count++)
		*(target++) = *(source++);
}