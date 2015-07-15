/* pe16-4.c -- */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

const double EPSILON = 1.00e-07;

void sleep(double);

int main(int argc, char ** argv)
{
	printf("The program will sleeping 10 seconds!\n");
	sleep(10);
	return EXIT_SUCCESS;
}

void sleep(double second)
{
	static clock_t ft = clock();
	static clock_t st;
	double use;

	for (;;){
		st = clock();
		use = (double)((st - ft) / CLOCKS_PER_SEC);
		if (fabs(use - second) < EPSILON)
			break;
	}
}
