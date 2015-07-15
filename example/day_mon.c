/*day_mon.c -- 打印每月的天数*/
#define MONTHS 12
#include <stdio.h>

int main(void)
{	
	int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;
	
	for(index = 0;index < MONTHS;index++){
		printf("Month %d has %2d days.\n",index + 1,days[index]);
	}
	return 0;
}
