/*
*计算工资
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

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
#define TEXT2 "a)$ 8.75/hr		b)$ 9.33/hr"
#define TEXT3 "c)$10.00/hr		d)$11.20/hr"
#define TEXT4 "q)quit"
/*工资*/
#define WAGES   8.75f
#define WAGES1  9.33f
#define WAGES2  10.00f
#define WAGES3  11.20f

char get_first(void);
void calc(float hr);
char get_choice(void);
unsigned int get_int(void);

int main(void)
{
	char  options;
	
	while( (options = get_choice()) != 'q' )
	{
		switch(options){
			case 'a':calc(WAGES);
					break;
			case 'b':calc(WAGES1);
					break;
			case 'c':calc(WAGES2);
					break;
			case 'd':calc(WAGES3);
					break;
					
			default:printf("Program error!\n");
		}
	}
	printf( "Bye!" );
	return 0;
}

/*获得第一个非空白字符*/
char get_first(void)
{
	char ch;
	
	while(isspace(ch = getchar()))
		continue;
	while(getchar() != '\n')	//清空缓存区
		continue;
	return ch;
}
/*获得正确的选项*/
char get_choice(void)
{
	char ch;
	
	printf( "%s\n",TEXT );
	printf( "%s\n",TEXT1 );
	printf( "%s\n",TEXT2 );
	printf( "%s\n",TEXT3 );
	printf( "%s\n",TEXT4 );
	printf( "%s\n:",TEXT );
	
	ch = get_first();
	while((ch < 'a' || ch > 'd') && ch != 'q')
	{
		printf("Please respond with a,b,c,d or q.\n:");
		
		ch = get_first();
	}
	return ch;
}
/*逻辑*/
void calc(float hr)
{
	unsigned int hours;
	float wages;
	float tax;
	
	printf("how many hours:");
	hours = get_int();
		
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
}
/*获得一个unsigned int*/
unsigned int get_int(void)
{
	unsigned int temp;
	char ch;
	
	while(scanf("%u",&temp) != 1){
			while((ch = getchar()) != '\n')
				putchar(ch);
			printf("is not an integer.\nPlease Enter an ");
			printf("integer value,such as 25,178,or 3:");
	}
	return temp;
}
