#include <stdio.h>
#include <ctype.h>

#define STR  "Enter the operation of your choice"
#define STR1 "a.add          s.subtract"
#define STR2 "m.multiply     d.divide"
#define STR3 "q.quit"

char get_choice(void);
char get_first(void);
float get_float(void);
void calc(char symbol);

int main(void)
{
	char options;
	
	while((options = get_choice()) != 'q')
	{
		switch(options){
			case 'a':calc('+');
					 break;
			case 's':calc('-');
					 break;
			case 'm':calc('*');
					 break;
			case 'd':calc('/');
					break;
			
			default:printf("Program Error!\n");
		}
	}
	printf("Bye.");
	return 0;
}

//获得适合的选项
char get_choice(void)
{
	char ch;
	
	printf("%s\n",STR);
	printf("%s\n",STR1);
	printf("%s\n",STR2);
	printf("%s\n:",STR3);
	
	ch = get_first();
	while(ch != 'a' && ch != 's' && ch != 
	'm' && ch != 'd' && ch != 'q'){
		printf("Please respond with a,s,m,d,or q.\n:");
		
		ch = get_first();
	}
	
	return ch;
}
//获得第一个非空白非标点符号字符
char get_first(void)
{
	char ch;
	
	while(isspace(ch = getchar()) || ispunct(ch))
		continue;
	while(getchar() != '\n')
		continue;
	return ch;
}
//获得一个单精度浮点
float get_float(void)
{
	float temp;
	char ch;
	
	while(scanf("%f",&temp) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an float.\nPlease enter an ");
		printf("float value,such as 12.23,124.00,or 23.00\n:");
	}
	
	return temp;
}
//进行计算
void calc(char symbol)
{
	double result;
	float  para;
	float  para1;
	
	switch(symbol)
	{
		case '+':printf("Enter first number\n:");
				 para = get_float();
				 printf("Enter seconder number\n:");
				 para1 = get_float();
				 result = para + para1;
				 break;
				 
		case '-':printf("Enter first number\n:");
				 para = get_float();
				 printf("Enter seconder number\n:");
				 para1 = get_float();
				 result = para - para1;
				 break;
				 
		case '*':printf("Enter first number\n:");
				 para = get_float();
				 printf("Enter seconder number\n:");
				 para1 = get_float();
				 result = para * para1;
				 break;
				 
		case '/':printf("Enter first number\n:");
				 para = get_float();
				 printf("Enter seconder number\n:");
				 para1 = get_float();
				 while(para1 < 1e-10){
					printf("Enter a number other than 0\n:");
					para1 = get_float();
				 }
				 result = para / para1;
				 break;
				 
		default:printf("Program Error!");
	}
	printf("%4.3f %c %4.3f = %4.3lf\n",para,symbol,para1,result);
}