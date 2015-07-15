/* vararr2d.c -- 使用变长数组的函数 */
#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, int ar[rows][cols]);

int main(void)
{
	int row,col;
	int rs = 3;
	int cs = 10;
	int junk[ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	
	int more_junk[ROWS - 1][COLS + 2] = {
		{20, 30, 40, 50, 60, 70},
		{5, 6, 7, 8, 9, 10}
	};
	
	int varr[rs][cs]; // 变长数组
	
	for(row = 0; row < rs; row++)
		for(col = 0; col < cs; col++)
			varr[row][col] = row * col + col;
	printf("3x5 array\n");
	printf("Sum of all elements = %d\n",
			sum2d(ROWS, COLS, junk));
	printf("2x6 array\n");
	printf("Sum of all elements = %d\n",
			sum2d(ROWS - 1, COLS + 2, more_junk));
	printf("3x10 VLA\n");
	printf("Sum of all elements = %d\n",
			sum2d(rs,cs,varr));
			
	return 0;
}

//带有一个VLA参数的函数
int sum2d(int rows, int cols, int ar[rows][cols])
{
	int row;
	int col;
	int tot = 0;
	
	for(row = 0; row < rows; row++)
		for(col = 0; col < cols; col++)
			tot += ar[row][col];
	
	return tot;
}