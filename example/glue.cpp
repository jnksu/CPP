//glue.c -- ʹ��##�����
#include <stdio.h>
#include <stdlib.h>

#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n)

int main(int argc, char ** argv)
{
	int XNAME(1) = 14;	//��Ϊint x1 = 14;
	int XNAME(2) = 20;	//��Ϊint x2 = 20;
	PRINT_XN(1);
	PRINT_XN(2);
	return EXIT_SUCCESS;
}
