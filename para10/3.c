//返回一个int数组中的最大数值
#include <stdio.h>

int max(const int * ar, int size);

int main()
{
	printf("The result is: %d\n", max((int [4]){546, 567, 878, 9876}, 4));
	return 0;
}

int max(const int * ar, int size)
{
	int temp,count;
	
	for(temp = *(ar++), count = 1; count < size; count++, ar++)
		temp = temp < *ar ? *ar : temp;
	
	return temp;
}