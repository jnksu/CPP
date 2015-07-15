// varargs.c -- ʹ�ÿɱ�����Ĳ���
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double sum(int, ...);

int main(int argc, char ** argv)
{
	double s, t;

	s = sum(3, 1.1, 2.5, 13.3);
	t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
	printf("return value for "
			"sum(3, 1.1, 2.5, 13.3):                %g\n", s);
	printf("return value for "
			"sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n", t);

	return EXIT_SUCCESS;
}

double sum(int lim, ...)
{
	va_list ap;			// �������ڴ�Ų����ı���
	double tot = 0;
	int index;
	va_start(ap, lim);	// ��ap��ʼ��Ϊ�����б�
	for (index = 0; index < lim; index++){
		tot += va_arg(ap, double);	// ���ʲ����б��е�ÿһ����Ŀ
	}
	va_end(ap);			// ������

	return tot;
}
