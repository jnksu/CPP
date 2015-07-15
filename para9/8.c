/*幂函数递归形式*/
#include <stdio.h>

double power(double para,int p);
double foo(int p,double para);

int main(void)
{
	double pow;
	int num;
	
	printf("please input the num the first is double seconder is integer(q for quit)\n:");
	while(scanf("%lf %d",&pow,&num) == 2){
		printf("the num %0.3lf pow %d is %0.7lf\n",pow,num,power(pow,num));
		printf("please input the num the first is double seconder is integer(q for quit)\n:");
	}
	
	return 0;
}

double power(double para,int p)
{
	double pow = 1.00;
	int temp;
	
	if( para < 1e-10 )
		return 0.00;
	if( p == 0 )
		return 1.00;
	
	if( p < 0 )
		temp = -p;
	else
		temp = p;
		
	pow = foo(temp,para);
	
	return p < 0 ? ((double)1.0 / pow) : pow; 
}

double foo(int p,double para)
{
	return p <= 1 ? para : (para * foo(p-1,para));
}