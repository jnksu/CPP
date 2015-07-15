// mems.c -- 使用memcpy() 和 memmove()函数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10
void show_array(const int * ar, int size);

int main(int argc, char ** argv)
{
	int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int target[SIZE];
	double curious[SIZE / 2] = {1.0, 2.0, 3.0, 4.0, 5.0};

	fputs("memcpy() used: \n", stdout);
	fputs("values (original data): \n", stdout);

	show_array(values, SIZE);
	memcpy(target, values, SIZE * sizeof(int));
	fputs("target (copy of values):\n", stdout);
	show_array(target, SIZE);

	fputs("\nUsing memmove() with overlapping ranges: \n", stdout);
	memmove(values + 2, values, 5 * sizeof(int));
	fputs("values -- elements 0-5 copied to 2-7:\n", stdout);
	show_array(values, SIZE);

	fputs("\nUsing memcpy() to copy double to int: \n", stdout);
	memcpy(target, curious, (SIZE / 2) * sizeof(double));
	fputs("target -- 5 double into 10 int positions: ", stdout);
	show_array(target, SIZE);

	return EXIT_SUCCESS;
}

void show_array(const int * ar, int size)
{
	int index;

	for (index = 0; index < size; index++)
		printf("%d ", *(ar + index));
	putchar('\n');

}
