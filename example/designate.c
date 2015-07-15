/*designate.c -- 使用指定初始化项目*/
#include <stdio.h>
#define MONTHS 12
int main(void)
{
	int days[MONTHS] = {31,28,[4] = 31,30,31,[1] = 29};
	int count;
	
	for(count = 0;count < MONTHS;count++)
		printf("%2d %d\n",count + 1,days[count]);
	return 0;
}