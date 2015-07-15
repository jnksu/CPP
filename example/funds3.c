/* funds3.c -- 把结构作为参数传递 */
#include <stdio.h>
#include <stdlib.h>
#define  FUNDLEN 50

struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(struct funds moolah); /* 参数是一个结构 */ 

int main(int argc, char ** argv)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"Lucky's Savings and loan",
		9237.11
	};
	printf("Stan has a total of $%.2f.\n", sum(stan));
	
	exit(EXIT_SUCCESS);
}

double sum(struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);
}
