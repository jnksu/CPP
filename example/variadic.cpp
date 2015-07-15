// variadic.c -- ¿É±äºê
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PR(x, ...) printf("Message " #x ":" __VA_ARGS__)

int main(int argc, char ** argv)
{
	double x = 48;
	double y;
	
	y = sqrt(x);
	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f, y = %.4f\n", x, y);
	return EXIT_SUCCESS;
}
