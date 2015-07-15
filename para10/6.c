//二维数组复制程序
#include <stdio.h>

void copy_ptr(double * source, double * target, int size);

int main(void)
{
	double source[5][5] = {
		{2.3, 3.33, 3.44, 32.4, 3.56},
		{2.5, 4.55, 4.55, 23.6, 4.56},
		{2.4, 3.44, 5.67, 34.6, 5.89},
		{2.6, 4.55, 4.78, 45.7, 7.89},
		{3.9, 4.55, 6.44, 56.9, 7.32}
	};
	double target[5][5];
	int count;
	
	for(count = 0; count < 5; count++)
		copy_ptr(source[count], target[count], 5);
	
	return 0;
}

void copy_ptr(double * source, double * target, int size)
{
	int count;
	
	for(count = 0; count < size; count++)
		*(target++) = *(source++);
}