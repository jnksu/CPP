/*求出两个double中的最小值*/
#include <stdio.h>

double min(double para,double para1);

int main(void)
{
	double num,num1;
	
	printf("Please input value(q for quit)\n:");
	
	while ( scanf("%lf %lf",&num,&num1) == 2){
		printf("The less than :%0.3lf",min(num,num1));
		printf("Please input value(q for quit)\n:");	
	}
	
	printf("Bye!");
	return 0;
}

double min(double para,double para1)
{
	return para < para1 ? para : para1;
}