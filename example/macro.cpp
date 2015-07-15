#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int cmp(const void * p1, const void * p2);
int main(int argc, char ** argv)
{
	int arr[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	qsort(arr, LEN, sizeof(int), cmp);
	
	for (int index = 0; index < LEN; index++){
		printf("%d ", arr[index]);
	}
	putchar('\n');
	return EXIT_SUCCESS;
}

int cmp(const void * p1, const void * p2)
{
	int * val1 = (int *)p1;
	int * val2 = (int *)p2;

	if (*val1 > *val2)
		return -1;
	else if (*val1 == *val2)
		return 0;
	else
		return 1;
}