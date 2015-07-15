#include <stdio.h>
#include <stdlib.h>
double power(double arg, int indices);

double power(double arg, int indices)
{
	int index;
	double temp = 1.0;
	
	for(index = 0; index < indices; index++)
			temp *= arg;
	
	return temp;
}

int main(int argc, char ** argv)
{
	int con;
	double con1;
	
	if( (con1 = atof(*(argv + 1))) && (con = atoi(*(argv + 2))) )
		printf("The result is %.3lf", power(con1, con));
	else
		printf("argument wrong!");
	return 0;
}