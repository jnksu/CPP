/*
*统计偶数和奇数
*/

#include <stdio.h>

int main(void)
{
	int num;
	int even = 0;
	int odd = 0;
	int count_even = 0;
	int count_odd = 0;
	
	while( scanf( "%d",&num ) == 1 )
	{
		if( num == 0 )
			break;
		if( (num % 2) == 0 ){
			count_even++;
			even += num;
		}
		else{
			count_odd++;
			odd += num;
		}
	}
	
	printf( "The even %2d,mean %f,odd %2d,mean %f",count_even,((float)even) /( (float) count_even),
		count_odd,((float)odd)/(float)count_odd);
	return 0;
}