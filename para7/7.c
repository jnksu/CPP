/*
*计算工资
*/

#include <stdio.h>
#define BASE_WAGES 10.00f					//每小时的工资[0,40],美元
#define FULL_WAGES 400.00f					//40小时的工资
#define FULL_TAX_W 300					 	//税率为0.15的最大金额										
#define FULL_TAX_W1 450						//税率为0.25最小金额减1
#define OVERTIME (1.5f * BASE_WAGES)		//超过40小时时(40,+&),每小时的工资
#define TAX 0.15f							//工资在[0,300],时的税率
#define FULL_TAX 45.00f						//300美元的税收
#define TAX1 0.2f							//(300,450],的税收
#define FULL_TAX1 75.00f					//450美元的税收
#define TAX2 0.25f							//工资在(450,+&)区间的税收
#define BASE_HOURS 40						//每周基本工作时间
 
int main(void)
{
	unsigned int hours;
	float wages;
	float tax;
	
	printf( "Enter number(q for quit):" );
	while( (scanf( "%u",&hours)) == 1 ){
	
		if( hours > BASE_HOURS )
			wages = FULL_WAGES + ( hours - BASE_HOURS ) * OVERTIME;
		else
			wages = hours * BASE_WAGES;
			
		if( wages > FULL_TAX_W1 )
			tax = FULL_TAX1 + ( wages - FULL_TAX_W1 ) * TAX2;
		else if( wages > FULL_TAX_W )
			tax = FULL_TAX  + ( wages - FULL_TAX_W ) * TAX1;
		else
			tax = wages * TAX;
			
	printf( "Your wages%10.3f$,tax%10.3f$,net margin%10.3f$\n",wages,tax,(float)(wages - tax) );	
	printf( "Enter number(q for quit):" );	
	}
	
	printf( "Bye!" );
	return 0;
}