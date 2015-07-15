/*fibonacci.c--输出斐波那契数列*/
#include <stdio.h>
int fibonacci(int para);

int main(void)
{
	int num;
	int count;
	
	printf("Please input (q for quit)\n:");
	while(scanf("%d",&num) == 1)
	{
		for(count = 1;count <= num;count++){
			printf("%5d",fibonacci(count));
		}
		putchar('\n');
		printf("Please input (q for quit)\n:");
	}
	return 0;
}
int fibonacci(int para)
{
	if( para > 2)
		return fibonacci(para - 1) + fibonacci(para -2);
	else
		return 1;
}