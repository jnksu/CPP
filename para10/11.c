//针对若干年的降水量数据, 计算年降水总量, 年均降水量, 以及月降水平均量
#include <stdio.h>

#define YEARS 5
#define MONTHS 12

float calc_rain(const float (* ptr_arr)[MONTHS], int years);
void avg_rain(const float (* ptr_arr)[MONTHS], int years);

int main(void)
{
	//把数组初始化为2000年到2004年的降水量数据
	const float rain[YEARS][MONTHS] ={
			{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
			{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
			{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4}, 
			{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
			{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	float total;
	
	printf(" YEAR RAINFALL (inches)\n");
	total = calc_rain(rain, YEARS);
	printf("\nThe yearly average is %.1f inches.\n\n",
			total/YEARS);
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct");
	printf(" Nov Dec\n");
	avg_rain(rain, YEARS);
	printf("\n");
	return 0;
}

float calc_rain(const float (* ptr_arr)[MONTHS], int years)
{
	int year,month;
	float subtot,total;
	
	for(year = 0, total = 0.0; year < years; year++)
	{
		for(month = 0, subtot = 0.0; month < MONTHS; month++)
			subtot += *(*(ptr_arr + year) + month);
		printf("%5d %15.1f\n", 2000 + year, subtot);
		total += subtot;
	}
	
	return total;
}

void avg_rain(const float (* ptr_arr)[MONTHS], int years)
{
	int year,month;
	float subtot;
	
	for(month = 0; month < MONTHS; month++)
	{
		for(year = 0, subtot = 0.0; year < years; year++)
			subtot += *(*(ptr_arr + year) + month);
		printf("%4.1f", subtot / YEARS);
	}
}