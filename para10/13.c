/* programming Exercise 10-12 */
#include <stdio.h>
#define ROWS 3
#define COLS 5

void store(double target[], int size);
double calc_avg(const double arr[], int size);
double calc_all_avg(int rows, int cols, double arr[rows][cols]);
void show_arr(int rows, int cols, double arr[rows][cols]);
double seek_max(int rows, int cols, double arr[rows][cols]);

int main(void)
{
	double stuff[ROWS][COLS];
	int row;
	
	for(row = 0; row < ROWS; row++)
	{
		printf("Enter %d numbers for row %d\n", COLS, row + 1);
		store(stuff[row], COLS);
	}
	
	printf("array contents:\n");
	show_arr(ROWS, COLS, stuff);
	
	for(row = 0; row < ROWS; row++)
		printf("average value of row %d = %g\n", row + 1, calc_avg(stuff[row], COLS));
	printf("average value of all rows = %g\n", calc_all_avg(ROWS, COLS, stuff));
	printf("largest value = %g\n", seek_max(ROWS, COLS, stuff));
	printf("Bye!\n");
	return 0;
}

void store(double target[], int size)
{
	int count;
	
	for(count = 0; count < size; count++)
	{
		printf("Enter value #%d: ", count + 1);
		scanf("%lf", &target[count]);
	}
}

double calc_avg(const double arr[], int size)
{
	int count;
	double total;
	
	for(count = 0, total = 0; count < size; count++)
		total += arr[count];
		
	if(size > 0)
		return total / size;
	else
		return 0.0;
}

double calc_all_avg(int rows, int cols, double arr[rows][cols])
{
	int row,col;
	double total;
	
	for(row = 0, total = 0.00; row < rows; row++)
		for(col = 0; col < cols; col++)
			total += arr[row][col];
			
	if(rows * COLS > 0)
		return total / (rows * COLS);
	else
		return 0.0;
}

void show_arr(int rows, int cols, double arr[rows][cols])
{
	int row,col;
	
	for(row = 0; row < rows; row++)
	{
		for(col = 0; col < cols; col++)
			printf("%g ", arr[row][col]);
		putchar('\n');	
	}		
}

double seek_max(int rows, int cols, double arr[rows][cols])
{
	double max_value = arr[0][0];
	int row,col;
	
	for(row = 0; row < rows; row++)
		for(col = 0; col < COLS; col++)
			max_value = max_value > arr[row][col] ? max_value : arr[row][col];
		
	return max_value;
}