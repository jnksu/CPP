/* mac_arg.c -- ���в����ĺ� */
#include <stdio.h>
#include <stdlib.h>

#define SQUARE(X) X * X
#define PR(X) printf("The result is %d.\n", X)

int main(int argc, char ** argv)
{
	int x = 4;
	int z;

	printf("x = %d\n", x);
	
	z = SQUARE(x);
	printf("Evaluating SQUARE(X): ");
	PR(z);

	z = SQUARE(2);
	printf("Evaluating SQUARE(2):");
	PR(z);

	printf("Evaluating SQUARE(x+2):");
	PR(SQUARE(x+2));

	printf("Evaluating 100/SQUARE(2):");
	PR(100 / SQUARE(2));

	printf("x is %d.\n", x);
	printf("Evaluating SQUARE(++x):");
	PR(SQUARE(++x));
	printf("After increamenting, x is %d.\n", x);
	return EXIT_SUCCESS;
}
