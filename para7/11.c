#include <stdio.h>

#define KOREA  	1.25f				//朝鲜
#define BEET   	0.65f				//甜菜
#define CARROT 	0.89f				//胡箩卜
#define BASE   	100					//折扣
#define REBATE 	0.05f				//折扣比率
#define WEIGHT 	5					//第一阶运输重量
#define WCOST  	3.50f				//第一阶费用
#define WEIGHT1	20					//第二阶运输重量
#define WCOST1	10.00f				//第二阶费用
#define WCOST2	8					//第三运输重量
#define WCOST3	0.1					//第三阶费用
/*显示的字符串*/
#define TEXT  "*****************************************************************"
#define TEXT1 "Enter the letter corresponding to the desired pay rate or action:"
#define TEXT2 "a)KOREA    b)BEET"
#define TEXT3 "c)CARROT   q)quit"

int main(void)
{
	char options;
	float korea_pound = 0;
	float beet_pound = 0;
	float carrot_pound = 0;
	float sum_cost = 0;
	float sum_pound = 0;
	float rebate = 0;
	float transport_cost = 0;
	
	printf( "%s\n",TEXT );
	printf( "%s\n",TEXT1 );
	printf( "%s\n",TEXT2 );
	printf( "%s\n",TEXT3 );
	printf( "%s\n:",TEXT );
	
	while( (options = getchar()) != 'q' ){	
		switch( options )
		{
			case 'a':
					printf( "Please input pounds:" );
					scanf( "%f",&korea_pound );
					getchar();
					break;
			case 'b':
					printf( "Please input pounds:" );
					scanf( "%f",&beet_pound );
					getchar();
					break;
			case 'c':
					printf( "Please input pounds:" );
					scanf( "%f",&carrot_pound );
					getchar();
					break;
			default:
					printf( "Please input correct values!\n" );
					getchar();
		}
			printf( "%s\n",TEXT );
			printf( "%s\n",TEXT1 );
			printf( "%s\n",TEXT2 );
			printf( "%s\n",TEXT3 );
			printf( "%s\n:",TEXT );
	}
	
	//计算总费用
	sum_cost = korea_pound * KOREA + beet_pound * BEET + carrot_pound * CARROT;
	//计算总磅数
	sum_pound = korea_pound + beet_pound + carrot_pound;
	//计算折扣
	if( sum_cost > BASE )
		rebate = sum_cost * REBATE;
	else
		rebate = 0;
	//计算运输费用
	if( sum_pound >= WEIGHT1 )
		transport_cost = WCOST2 + sum_pound * WCOST3;
	else if( sum_pound > WEIGHT )
		transport_cost = WCOST1;
	else
		transport_cost = WCOST;
	
	//显示信息
	printf( "The per pound fee is %10.5f$\n",sum_cost / sum_pound );
	printf( "The korea pound      %10.5f$\n",korea_pound );
	printf( "The Korea fee        %10.5f$\n",korea_pound * KOREA );
	printf( "The beet pound       %10.5f$\n",beet_pound );
	printf( "The beet fee         %10.5f$\n",beet_pound * BEET );
	printf( "The carrot pound     %10.5f$\n",carrot_pound );
	printf( "The carrot fee       %10.5f$\n",carrot_pound * CARROT );
	printf( "The sum pound        %10.5f$\n",sum_pound );
	printf( "The sum fee          %10.5f$\n",sum_cost );
	printf( "The rebate           %10.5f$\n",rebate );
	printf( "The transport fee    %10.5f$\n",transport_cost );
	printf( "The total cost       %10.5f$", (sum_cost + transport_cost) - rebate );
	
	return 0;
}
