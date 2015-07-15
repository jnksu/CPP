/*factor.c--使用循环和递归计算阶乘*/
#include <stdio.h>

long fact(int para);
long rfact(int para);

int main(void)
{
	int num;
	
	printf("This program calculates factorials.\n");
	printf("Enter a value in the range 0-12(q to quit):\n");
	while(scanf("%d",&num))
	{
		if(num < 0)
			printf("No negative numbers,please.\n");
		else if(num > 12)
			printf("Keep input under 13.\n");
		else
		{
			printf("loop: %d factorial = %ld\n",num,fact(num));
			printf("recursion: %d factorial = %ld\n",num,rfact(num));
		}
		printf("Enter a value in the range 0-12(q to quit):\n");
	}
	printf("Bye.\n");
	return 0;
} 

long fact(int para)//使用循环计算阶乘
{
	long ans;
	
	for(ans = 1; para > 1;para--)
		ans *= para;
	return ans;
}

long rfact(int para)//使用递归计算阶乘
{
	long ans;
	
	if(para > 0)
		ans = para * rfact(para - 1);
	else
		ans  = 1;
	return ans; 
}