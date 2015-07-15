/*最大值替换*/

#include <stdio.h>

void instead(double * para,double * para1);

int main(void)
{
	double para = 16234.00;
	double para1 = 17.00;
	
	printf("The first values %8.3lf,%8.3lf\n",para,para1);
	instead( &para,&para1 );
	printf("Now the values %8.3lf,%8.3lf",para,para1);
	
	return 0;
}

void instead(double * para,double * para1)
{
	*para = *para1 = (*para > *para1 ? *para : *para1);
}

