#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int);
void sort(int * ptr, int size);
void pri_arr(int * ptr, int size, int gap);

int main(int argc, char ** argv)
{
	int rand[100];
	int i;
	
	srand((unsigned int)time(0));
	for(i = 0; i < 100; i++)
		rand[i] = random(100);
	printf("Origin:\n");
	pri_arr(rand, 100, 10);
	
	sort(rand, 100);
	
	printf("Result:\n");
	pri_arr(rand, 100, 10);
	return 0;
}

int random(int lim)
{
	int num = -1;
	if(lim > 1)
		num = rand() % lim + 1;
	return num;
}

void sort(int * ptr, int size)
{
	int i,nest;
	
	for(i = 0; i < size - 1; i++)
		for(nest = i + 1; nest < size; nest++){
				if(*(ptr + i) < *(ptr + nest))
				{
					*(ptr + i) ^= *(ptr + nest);
					*(ptr + nest) ^= *(ptr + i);
					*(ptr + i) ^= *(ptr + nest);
				}
		}
}

void pri_arr(int * ptr, int size, int gap)
{
	int i;
	
	for(i = 0; i < size; i++){
		printf(" %4d", *(ptr + i));
		if( (i + 1) % gap == 0)
			putchar('\n');
	}
}
