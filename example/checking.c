/*checking.c--����ȷ��*/
#include <stdio.h>
#include <stdbool.h>
//ȷ��������һ������
int get_int(void);
//ȷ�Ϸ�Χ�����½��Ƿ���Ч
bool bad_limits(int begin,int end,int low,int high);
//�����a��b֮���������ƽ����
double sum_quares(int a,int b);

int main(void)
{
	const int MIN = -1000;	//��Χ���½�����
	const int MAX = +1000;	//��Χ���Ͻ�����
	int start;				//��Χ���½�
	int stop;				//��Χ���Ͻ�
	double answer;
	
	printf( "This program computes the sum of the squares of "
			"integers in a range.\nThe lower bound should not "
			"be less than -1000 and\nthe upper bound should not "
			"be more than +1000.\nEnter the limits (enter 0 for "
			"both limits to quit):\nlower limit: ");
	start = get_int();
	printf( "upper limit: " );
	stop = get_int();
	while(start != 0 || stop != 0)
	{
		if(bad_limits(start,stop,MIN,MAX))
			printf("Please try again.\n");
		else{
			answer = sum_quares(start,stop);
			printf("The sum of the squares of the integer from");
			printf("from %d to %d is %g\n",start,stop,answer);
		}
		printf("Enter the limits(enter 0 for both limits to quit):\n");
		printf("lower limit: ");
		start = get_int();
		printf( "upper limit: ");
		stop = get_int();
	}
	printf("Done.\n");
	return 0;
}
int get_int(void)
{
	int input;
	char ch;
	
	while(scanf("%d",&input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);//ɾ�����������
		printf(" is not an integer.\nPlease enter an");
		printf("integer value,such as 25,-178,or 3:");
	}
	return input;
}
double sum_quares(int temp,int temp1)
{
	double total = 0;
	int count;
	
	for(count = temp;count <=temp1;count++)
		total += count * count;
		
	return total;
}

bool bad_limits(int begin,int end,int low, int high)
{
	bool not_good = false;
	
	if(begin > end)
	{
		printf("%d isn't smaller than %d.\n",begin,end);
		not_good = true;
	}
	if(begin < low || end < low)
	{
		printf("values must be %d or greater.\n",low);
		not_good = true;
	}
	if( begin > high || end > high)
	{
		printf("Values must be %d or less.\n",high);
		not_good = true;
	}
	return not_good;
}