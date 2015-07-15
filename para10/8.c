//数组复制显示程序·
#include <stdio.h>

void copy_arr(int rows, int cols, const double source[rows][cols], double target[rows][cols]);
void show_arr(int rows, int cols, const double ar[rows][cols]);

int main(void)
{
	const double source[3][5] = {
		{4.4, 5.6, 7.8, 9.3, 7.1},
		{3.8, 6.9, 3.5, 7.0, 2.7},
		{5.9, 7.8, 4.8, 3.0, 5.9}
	};
	double target[3][5];
	
	copy_arr(3, 5, source, target);
	show_arr(3, 5, target);
	return 0;
}

void copy_arr(int rows, int cols, double source[rows][cols], double target[rows][cols])
{
	int row,col;
	
	for(row = 0; row < rows; row++)
		for(col = 0; col < cols; col++)
			target[row][col] = source[row][col];
}

void show_arr(int rows, int cols, double ar[rows][cols])
{
	int row,col;
	
	for(row = 0; row < rows; row++)
	{
		for(col = 0; col < cols; col++)
			printf("%7.3lf", ar[row][col]);
		putchar('\n');
	}	
}