/*recur.c --递归举例*/
#include <stdio.h>

void up_and_down(int);

int main(void)
{
	up_and_down(1);
	return 0;
}

void up_and_down(int para)
{
	printf("Level %d:n location %p\n",para,&para);
	if( para < 4)
		up_and_down(para + 1);
	printf("LEVEL %d:n location %p\n",para,&para);
}