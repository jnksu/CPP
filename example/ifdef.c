/* ifdef.c -- 使用条件编译 */
#include <stdio.h>
#include <stdlib.h>
#define JUST_CHECKING
#define LIMIT 4

int main(int argc, char ** argv)
{
	int index;
	int total = 0;
	
	for(index = 1; index <= LIMIT; index++)
	{
		total += 2 * i * i + 1;
#ifdef JUST_CHECKING
		printf("i = %d, running total = %d\n", index, total);
#endif
	}
	printf("Grand total = %d\n", total);
	
	return EXIT_SUCCESS;
}

