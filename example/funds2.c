/* funds2.c -- 传递指向结构的指针 */
#include <stdio.h>
#include <stdlib.h>
#define FUNDLEN 50

struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds *); /* 参数是一个指针 */

int main(int argc, char ** argv)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"Lucky's Savings and loan",
		9237.11
	};
	printf("Stan has total of $%.2f.\n", sum(&stan));
	
	exit(EXIT_SUCCESS);
}

double sum(const struct funds * money)
{
	return (money->bankfund + money->savefund);
}