/*pe14-11.c -- 使用函数指针*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define ARRLEN 100

typedef double (* DFP)(double);
void show(double *,int);
double foo(double);
double foo1(double);
void transform(double *, double *, int, DFP);

int main(int argc, char ** argv)
{

	int index;
	double source[ARRLEN];
	double target[ARRLEN];
	//对数组赋值
	for(index = 0; index < ARRLEN; index++)
		source[index] = index + 1;
		
	transform(source, target, ARRLEN,foo);
	show(target, ARRLEN);
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	
	transform(source, target, ARRLEN,foo1);
	show(target, ARRLEN);
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	
	transform(source, target, ARRLEN,sin);
	show(target, ARRLEN);
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	
	transform(source, target, ARRLEN,tan);
	show(target, ARRLEN);
	
	exit(EXIT_SUCCESS);
}
//作用函数到数组
void transform(double * source, double * target, int size, DFP traFun)
{
	int index;

	for (index = 0; index < size; index++){
		*(target + index) = (*traFun)(*(source + index));
	}

}
//显示数组的内容
void show(double * arr, int size)
{
	int index;

	for(index = 0; index < size; index++){
		printf("%8.3lf ", *(arr + index));
		if((index + 1) % 10 == 0)
			putchar('\n');	
	}
}

double foo(double arg)
{
	return arg * 10.0;
}

double foo1(double arg)
{
	return arg + 10.0;
}
