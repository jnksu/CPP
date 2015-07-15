/* array2d.c -- 处理二维数组的函数 */
#include <stdio.h>

#define ROWS 3
#define COLS 4

void sum_rows(int ar[][COLS], int rows);
void sum_cols(int ar[][COLS], int cols);
int sum2d(int (*ar)[COLS], int rows);

int main(void)
{
	int junk[ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	
	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
	
	return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
	int row;
	int col;
	int tot;
	
	for(row = 0; row < rows; row++)
	{
		tot = 0;
		for(col = 0; col < COLS; col++)
			tot += ar[row][col];
		printf("row %d: sum = %d\n", row, tot);
	}
}

void sum_cols(int ar[][COLS], int rows)
{
	int row;
	int col;
	int tot;
	
	for(col = 0; col < COLS; col++)
	{
		tot = 0;
		for(row = 0; row < rows; row++)
			tot += ar[row][col];
		printf("col %d: sum = %d\n", col, tot);
	}
}

int sum2d(int ar[][COLS], int rows)
{
	int row;
	int col;
	int tot = 0;
	
	for(row = 0; row < rows; row++)
	{
		for(col = 0; col < COLS; col++)
			tot += ar[row][col];
	}
	
	return tot;
}
