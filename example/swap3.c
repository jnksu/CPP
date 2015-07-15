/*swap3.c -- 使用指针完成交换*/

#include <stdio.h>

void interchange(int * para,int * para1);

int main(void)
{
	int num = 5;
	int num1 = 10;
	
	printf("Originally para = %d and para1 = %d.\n",num,num1);
	interchange( &num,&num1);	/*向函数传送地址*/
	printf("Now para = %d and para1 = %d\n",num,num1);
	return 0;
}

void interchange(int * para,int * para1)
{
	*para ^= *para1;
	*para1 ^= *para;
	*para ^= *para1;
}