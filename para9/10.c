/*斐波那契数列*/
#include <stdio.h>
unsigned long fibonacci(int n);

int main(void)
{
	printf("%ld",fibonacci(13));
	return 0;
}

unsigned long fibonacci(int n)
{
	long temp,temp1;
	int count = 0;
	
	if(n <= 2)
		return 1;
		
	for(temp = 1,temp1 = 1,count = 0;count < n - 2;count++)
	{
		int foo = temp;
		temp = temp1;
		temp1 = foo + temp1;
	}
	
	return temp1;
}