// pe12-8.c
#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int * ar, int size);

int main(int argc, char ** argv)
{
	int * pa;
	int size;
	int value;
	
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	while(size > 0){
		printf("Enter the initialization value: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if(pa){
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements(<1 to quit):");
		scanf("%d", &size);
	}
	printf("Done.\n");
	exit(EXIT_SUCCESS);
}

int * make_array(int elem, int val)
{
	int index;
	int * ptr;
	
	ptr = (int *)malloc(elem * sizeof(int));
	for(index = 0; index < elem; index++)
		*(ptr + index) = val;
	
	return ptr;
}

void show_array(const int * ar, int size)
{
	int index;
	
	for(index = 0; index < size; index++){
		printf("%4d", *(ar + index));
		if((index + 1) % 8 == 0 && index != (size - 1))
			putchar('\n');
	}
	putchar('\n');
}
