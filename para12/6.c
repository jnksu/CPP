#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME 1000
#define LEN 10

int random(int lim);

int main(int argc, char ** argv)
{
	int * count = (int *)malloc(LEN * sizeof(int));
	int index;
	unsigned int seed = 123456;
	
	printf("The result is:\n");
	for(index = 0; index < LEN; index++){
		
		register int index;
		
		for(index = 0; index < LEN; index++){
			*(count + index) = 0;
		}
		srand(seed++);
		for(index = 0; index < TIME; index++){
			(*(count + random(LEN)))++;
		}
	
		for(index = 0; index < LEN; index++){
			printf("%2d:%4d ", index + 1, *(count + index));
		}
		
		putchar('\n');
	}
	
	free(count);
	exit(EXIT_SUCCESS);
}

int random(int lim)
{
	int res = -1;
	
	res = rand() % lim;
	
	return res;
}
