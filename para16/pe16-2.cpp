/* pe16-2.c -- 使用指令定义宏 */
#include <stdio.h>
#include <stdlib.h>

#define MACRO(X, Y) 1 / ((1 / (X) + 1 / (Y)) / 2)

int main(int argc, char ** argv)
{
	double x, y, ans;

	while (2 == scanf("%lf %lf", &x, &y)){
		ans = MACRO(x, y);
		printf("%g = harmonic mean of %g %g.\n", ans, x, y);
		ans = MACRO(x - y, x + y);
		printf("%g = harmonic mean of %g %g.\n", ans, x - y, x + y);
	}

	fputs("bye\n", stdout);
	return EXIT_SUCCESS;
}
