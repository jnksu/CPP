/* subst.c -- ���ַ����н����滻 */
#include <stdio.h>
#include <stdlib.h>
#define PSQR(x) printf("The square of "#x" is %d.\n", ((x)*(x)))
int main(int argc, char ** argv)
{
	int y = 5;

	PSQR(y);
	PSQR(2 + 4);

	return EXIT_SUCCESS;
}