/*
*���㹤��
*/

#include <stdio.h>
#include <stdbool.h>
#define BASE_WAGES 10.00f					//ÿСʱ�Ĺ���[0,40],��Ԫ
#define FULL_WAGES 400.00f					//40Сʱ�Ĺ���
#define FULL_TAX_W 300					 	//˰��Ϊ0.15�������										
#define FULL_TAX_W1 450						//˰��Ϊ0.25��С����1
#define OVERTIME 1.5						//����40Сʱʱ(40,+&),ÿСʱ�Ĺ���(����)
#define TAX 0.15f							//������[0,300],ʱ��˰��
#define FULL_TAX 45.00f						//300��Ԫ��˰��
#define TAX1 0.2f							//(300,450],��˰��
#define FULL_TAX1 75.00f					//450��Ԫ��˰��
#define TAX2 0.25f							//������(450,+&)�����˰��
#define BASE_HOURS 40						//ÿ�ܻ�������ʱ��
/*��ʾ���ַ���*/
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
 
	
	/*����*/
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
	
	/*�߼�*/
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