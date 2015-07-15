/*binary.c--以二进制形式输出整数*/
#include <stdio.h>
void to_binary(unsigned long para);

int main(void)
{
	unsigned long number;
	
	printf("Enter an integer (q to quit):\n");
	while(scanf("%lu",&number) == 1)
	{
		printf("Binary equivalent: ");
		to_binary(number);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");
	}
	printf("Done.\n");
	
	return 0;
}
void to_binary(unsigned long para)/*递归函数*/
{
	if( para >= 2)
		to_binary( para / 2);
	para % 2 ? putchar('1'):putchar('0');
}