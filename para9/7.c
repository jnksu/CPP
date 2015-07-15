/*幂函数*/
#include <stdio.h>

double power(double para,int p);

int main(void)
{
	double pow;
	int num;
	
	printf("please input the num(q for quit)\n:");
	while(scanf("%lf %d",&pow,&num) == 2){
		printf("the num %0.3lf pow %d is %0.7lf\n",pow,num,power(pow,num));
		printf("please input the num(q for quit)\n:");
	}
	
	return 0;
}

double power(double para,int p)
{
	double pow = 1.00;
	int count;
	int temp;
	
	if( para < 1e-10 )
		return 0.00;
	if( p == 0 )
		return 1.00;
	
	if( p < 0 )
		temp = -p;
	else
		temp = p;
	
	for(count = 1;count <= temp;count++)
		pow *= para;
	
	return p < 0 ? ((double)1.0 / pow) : pow; 
}