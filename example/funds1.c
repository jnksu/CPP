/* funds1.c -- �ѽṹ��Ա��Ϊ�������� */
#include <stdio.h>
#include <stdlib.h>
#define FUNDLEN 50

struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(double, double);

int main(int argc, char ** argv)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		3024.72,
		"Lucky's Savings and Loan",
		9237.11
	};
	
	printf("Stan has a total of $%.2f.\n",
		sum(stan.bankfund, stan.savefund));
	exit(EXIT_SUCCESS);
}

/* ������double����� */ 
double sum(double x, double y)
{
	return (x + y);
}
