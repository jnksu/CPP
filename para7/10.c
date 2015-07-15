#include <stdio.h>
/*税金种类*/
#define BASE 0.15f
#define OVER 0.28f
#define BACHELORDOM	17850
#define HOUSEHOLD	23900
#define MARRIED		29750
#define DIVORCED	14875
/*显示的字符串*/
#define TEXT  "*****************************************************************"
#define TEXT1 "Enter the number corresponding to the desired pay rate or action:"
#define TEXT2 "1)BACHELORDOM    2)HOUSEHOLD"
#define TEXT3 "3)MARRIED        4)DIVORCED"
#define TEXT4 "5)quit"

int main(void)
{
	char  options = 0;				//用户选项
	float wages;					//工资
	float tax;						//税收
	float limit;					//相应的税率界限
	
	/*界面*/
	printf( "%s\n",TEXT );
	printf( "%s\n",TEXT1 );
	printf( "%s\n",TEXT2 );
	printf( "%s\n",TEXT3 );
	printf( "%s\n",TEXT4 );
	printf( "%s\n:",TEXT );
	
	
	while( (options = getchar()) != '5' )
	{	/*根据用户选项设置相应税率*/
		switch( options ){
			case  '1':
					limit = (float)BACHELORDOM;
					getchar();
					break;
			case  '2':
					limit = (float)HOUSEHOLD;
					getchar();
					break;
			case  '3':
					limit = (float)MARRIED;
					getchar();
					break;
			case  '4':
					limit = (float)DIVORCED;
					getchar();
					break;
			
			default:
					printf( "Please input correct values!\n:" );
					getchar();
		}
		/*提示输入相应工资并进行计算*/
		if( options >= '1' && options <= '4' ){
			printf( "Enter number(q for quit):" );
			while( scanf( "%f",&wages ) == 1 )
			{
				if( wages > limit )
					tax = ( wages - limit ) * OVER + limit * BASE;
				else
					tax = wages * BASE;
				
				printf( "Your tax%10.5f$\n",tax );
				printf( "Enter number(q for quit):" );
			}
			getchar();
			getchar();
			
			/*界面*/
			printf( "%s\n",TEXT );
			printf( "%s\n",TEXT1 );
			printf( "%s\n",TEXT2 );
			printf( "%s\n",TEXT3 );
			printf( "%s\n",TEXT4 );
			printf( "%s\n:",TEXT );
		}
	}
	
	printf( "Bye!" );
	return 0;
}