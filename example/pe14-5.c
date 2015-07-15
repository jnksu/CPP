/*pe14-5.c -- 一个测试计算月份函数的驱动程序*/
#include <stdio.h>
#include <stdlib.h>

int count_days(char months);

struct month{
	char name[11];
	char acronym[4];
	char days;
	char num;
};

struct month year[12] = {
	{"January",  "Jan", 31,  1},
	{"February", "Feb", 28,  2},
	{"March",    "Mar", 31,  3},
	{"April",    "Apr", 30,  4},
	{"May",      "May", 31,  5},
	{"June",	 "Jun", 30,  6},
	{"July",	 "Jul", 31,  7},
	{"August",   "Aug", 31,  8},
	{"September","Sep", 30,  9},
	{"October",  "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 31, 12}
};

int main(int argc, char ** argv)
{
	fprintf(stdout, "Test:%d\n", count_days(12));
	exit(EXIT_SUCCESS);
}

int count_days(char months)
{
	extern struct month year[];
	
	int temp = 0;
	int index;
	
	if(months > 12 || months < 1)
		return -1;
	
	for(index = 0; index < months; index++){
		temp += year[index].days;
	}
	
	return temp;
}
