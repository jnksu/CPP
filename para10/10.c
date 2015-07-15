//倍增并显示数组
#include <stdio.h>

#define COLS 5

void show_arr(int rows,const int (* ptr_arr)[COLS]);
void increase(int rows, int (* ptr_arr)[COLS]);
 
int main(void)
{
	int arr[3][5] = {
		{23, 45, 32, 35, 49},
		{34, 56, 26, 39, 48},
		{89, 45, 28, 38, 61}
	};
	
	show_arr(3, arr);
	increase(3, arr);
	putchar('\n');
	show_arr(3, arr);
	
	return 0;
}

void show_arr(int rows, const int (* ptr_arr)[COLS])
{
	int row,col;
	
	for(row = 0; row < rows; row++)
	{
		for(col = 0; col < COLS; col++)
			printf("%7d", *(*(ptr_arr + row) + col));
		putchar('\n');
	}		
}

void increase(int rows, int (* ptr_arr)[COLS])
{
	int row,col;
	
	for(row = 0; row < rows; row++)
		for(col = 0; col < COLS; col++)
			*(*(ptr_arr + row) + col) *= 2; 
}
