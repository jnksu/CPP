// flc.c -- 有趣的常量
#include <stdio.h>

#define COLS 4

int sum2d(int ar[][COLS], int rows);
int sum(int ar[], int size);

int main(void)
{
	int total1, total2, total3;
	int * pt1;
	int (*pt2) [COLS];
	
	pt1 = (int [2]){10, 20};
	pt2 = (int [2][COLS]){{1, 2, 3, -9},{4, 5, 6, -8}};
	
	total1 = sum(pt1, 2);
	total2 = sum2d(pt2, 2);
	total3 = sum((int []){4, 4, 4, 5, 5, 5}, 6);
	
	printf("total = %d\n", total1);
	printf("total = %d\n", total2);
	printf("total = %d\n", total3);
	
	return 0;
}

int sum(int ar[], int size)
{
	int rear;
	int total = 0;
	
	for(rear = 0; rear < size; rear++)
		total += ar[rear];
	
	return total;
}

int sum2d(int ar[][COLS], int rows)
{
	int row;
	int col;
	int tot = 0;
	
	for(row = 0; row < rows; row++)
		for(col = 0;col < COLS; col++)
			tot += ar[row][col];
	
	return tot;
}