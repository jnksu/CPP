// doubincl.c -- 两次包含同一头文件
#include <stdio.h>
#include <stdlib.h>
#include "names_st.h"
#include "names_st.h"

int main(int argc, char ** argv)
{
	names winner = {"Less", "Ismoor"};
	printf("The Winnner is %s %s.\n", winner.first, winner.last);
	return EXIT_SUCCESS;
}
