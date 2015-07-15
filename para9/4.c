/*求出谐均值*/
#include <stdio.h>

double harmonic(double para,double para1);

int main(void)
{
	double input,input1;
	
	printf("please input the value(q for quit):");
	
	while((scanf("%lf %lf",&input,&input1)) == 2)
	{
		printf("The result is: %0.3lf\n",harmonic(input,input1));
		printf("please input the value(q for quit):");
	}
	printf("Bye!");
	return 0;
}
double harmonic(double para,double para1)
{
	double temp;
	
	temp = (((double)1 / para)+((double)1 / para1)) / 2;
	
	return (double)1 / temp; 
}
