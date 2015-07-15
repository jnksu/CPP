/*
 * coldDays.c
 *
 *  Created on: 2013-12-27
 *      Author: Mr_Li
 */

#include <stdio.h>
int main(void)
{
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;

	printf( "Enter the list of daily low temperatures.\n" );
	printf( "Use celsius,and enter q to quit.\n" );
	while( scanf( "%f",&temperature) == 1 )
	{
		all_days++;
		if( temperature < FREEZING )
			cold_days++;
	}
	if( all_days != 0 )
		printf( "%d days total:%.1f%% were below freezing.\n",
				all_days, 100.0 * (float) cold_days / all_days );
	if( all_days == 0 )
		printf( "No data entered!\n" );
	return 0;

}
