/*
*���㹤��
*/

#include <stdio.h>
#define BASE_WAGES 10.00f					//ÿСʱ�Ĺ���[0,40],��Ԫ
#define FULL_WAGES 400.00f					//40Сʱ�Ĺ���
#define FULL_TAX_W 300					 	//˰��Ϊ0.15�������										
#define FULL_TAX_W1 450						//˰��Ϊ0.25��С����1
#define OVERTIME (1.5f * BASE_WAGES)		//����40Сʱʱ(40,+&),ÿСʱ�Ĺ���
#define TAX 0.15f							//������[0,300],ʱ��˰��
#define FULL_TAX 45.00f						//300��Ԫ��˰��
#define TAX1 0.2f							//(300,450],��˰��
#define FULL_TAX1 75.00f					//450��Ԫ��˰��
#define TAX2 0.25f							//������(450,+&)�����˰��
#define BASE_HOURS 40						//ÿ�ܻ�������ʱ��
 
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