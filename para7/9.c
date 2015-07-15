/*
*求出小于输入数字的所有素数
*/

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	unsigned int num;
	unsigned int count;
	unsigned int count_nest;
	bool flag = false;
	
	printf( "Please input the num:" );
	scanf( "%u",&num );
	
	/*对小于num的每个数进行素数测试*/
	for(count = 2;count <= num;count++ ){
		
		for( count_nest = 2;count_nest * count_nest <= count;count_nest++ )
		{
				if(count % count_nest == 0){
					flag = true;
					break;
				}
		}
		
		if( !flag )
			printf( "less than num prim:%4d\n",count );
		
		flag = false;	
	}
	
	printf( "Bye!" );
	
	return 0;
}