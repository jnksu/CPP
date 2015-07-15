/*hotel -- 旅馆管理函数*/
#include <stdio.h>
#include "hotel.h"

int menu(void)
{
	int code,status;
	
	printf("\n%s%s\n",STARS,STARS);
	printf("Enter the number of the desired hotel: \n");
	printf("1)Fairfield Arms     2)Hotel Olympic\n");
	printf("3)Chertworthy Plazza 4)The Stockton\n");
	printf("5)quit\n");
	printf("%s%s\n",STARS,STARS);
	while((status = scanf("%d",&code)) != 1 || 
	(code < 1 || code > 5))
	{
		if(status != 1)
			scanf("%*s");
		printf("Enter an integer from 1 to 5,Please.\n");
	}
	return code;
}
int getnights(void)
{
	int nights;
	
	printf("How many nights are needed? ");
	while(scanf("%d",&nights) != 1)
	{
		scanf("%*s");
		printf("Please enter an integer,such as 2.\n");
	}
	return nights;
}
void showprice(double rate,int nights)
{
	int count;
	double total = 0.0;
	double factor = 1.0;
	for(count = 1;count <= nights;count++,factor *= DISCOUNT)
		total += rate * factor;
	printf("The total cost will be $%0.2f.\n",total);
}
