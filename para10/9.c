// 数组相加程序
#include <stdio.h>

void add_arr(const int  * source, const int * source1, int * target, int size);
void show_arr(const int * source, int size);																																
int main(void)
{	
	 int source[4] = {2, 4, 5, 8};
	 int source1[4] = {1, 0, 4, 6};
	
	int target[4];
	
	add_arr(source, source1, target, 4);
	show_arr(target, 4);
	return 0;
}

void add_arr(const int * source, const int * source1, int * target, int size)
{
	int count;
	
	for(count = 0; count < size; count++)
		*(target + count) = *(source + count) + *(source1 + count);
}

void show_arr(const int * source, int size)
{
	int count;
	
	for(count = 0; count < size; count++)
		printf("%4d", *(source + count));
}