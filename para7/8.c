/*
*计算工资
*/

#include <stdio.h>
#include <stdbool.h>
#define BASE_WAGES 10.00f					//每小时的工资[0,40],美元
#define FULL_WAGES 400.00f					//40小时的工资
#define FULL_TAX_W 300					 	//税率为0.15的最大金额										
#define FULL_TAX_W1 450						//税率为0.25最小金额减1
#define OVERTIME 1.5						//超过40小时时(40,+&),每小时的工资(倍数)
#define TAX 0.15f							//工资在[0,300],时的税率
#define FULL_TAX 45.00f						//300美元的税收
#define TAX1 0.2f							//(300,450],的税收
#define FULL_TAX1 75.00f					//450美元的税收
#define TAX2 0.25f							//工资在(450,+&)区间的税收
#define BASE_HOURS 40						//每周基本工作时间
/*显示的字符串*/
#define TEXT  "*****************************************************************"
#define TEXT1 "Enter the number corresponding to the desired pay rate or action:"
#define TEXT2 "1)$ 8.75/hr		2)$ 9.33/hr"
#define TEXT3 "3)$10.00/hr		4)$11.20/hr"
#define TEXT4 "5)quit"

int main(void)
{
	unsigned int hours;
	float wages;
	float tax;
	char  options;
	float hr;
 
	
	/*界面*/
	printf( "%s\n",TEXT );
	printf( "%s\n",TEXT1 );
	printf( "%s\n",TEXT2 );
	printf( "%s\n",TEXT3 );
	printf( "%s\n",TEXT4 );
	printf( "%s\n:",TEXT );
	
	options = getchar();
	
	while( options < '1' || options > '5' ){
		printf( "Please input correct values\n:" );
		
		options = getchar(); 
	}		
	
	switch(options)
	{
		case '1':hr = 8.75f;break;
		case '2':hr = 9.33f;break;
		case '3':hr = 10.0f;break;
		case '4':hr = 11.2f;break;
		case '5':printf( "Bye!" );return;
	}
	
	/*逻辑*/
	printf( "Enter number(q for quit):" );
	while( (scanf( "%u",&hours)) == 1 ){
		
		if( hours > BASE_HOURS ){
			hr *= OVERTIME;
			wages = FULL_WAGES + ( hours - BASE_HOURS ) * hr ;
		}
		else
			wages = hours * hr;
				
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