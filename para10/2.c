// 复制数组
#include <stdio.h>

void copy_arr(const double source[], double target[], int size);
void copy_ptr(const double * source, double * target, int size);

int main(void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	copy_arr(source, target1, 5);
	copy_ptr(source, target2, 5);
	
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
	int count;
	for(count = 0; count < size; count++)
		*(target++) = *(source++);
}