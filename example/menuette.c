/*menuette.c--菜单技术*/
#include <stdio.h>

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void)
{
	int choice;
	void count(void);
	
	while((choice = get_choice()) != 'q')
	{
		switch(choice)
		{
			case 'a':printf("Buy low,sell high.\n");
					break;
			case 'b':printf("\a");
					break;
			case 'c':count();
					break;
			default:printf("Program error!\n");
		}
	}
	printf("Bye.\n");
	return 0;
}
void count(void)
{
	int num,count;
	
	printf("count how far?Enter an integer:\n");
	num = get_int();
	
	for( count = 1;count <= num;count++ )
		printf("%d\n",count);
	while(getchar() != '\n')
		continue;
}

char get_choice(void)
{
	int ch;
	
	printf("Enter the letter of you choice:\n");
	printf("a.advice                 b.bell\n");
	printf("c.count                  q.quit\n");
	ch = get_first();
	while((ch < 'a' || ch > 'c') && ch != 'q')
	{
		printf("Please respond with a,b,c, or g.\n");
		
		ch = get_first();
	}
	return ch;
}

char get_first(void)
{
	char ch;
	
	ch = getchar();
	while(getchar() != '\n')
		continue;
	return ch;
}

int get_int(void)
{
	int input;
	char ch;
	
	while(scanf("%d",&input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);//剔除错误的输入
		printf("is not an integer.\nPlease enter an ");
		printf("integer value,such as 25,-178,or 3:");
	}
	return input;
}