/* preproc.c �򵥵�Ԥ�������� */
#include <stdio.h>
#include <stdlib.h>
#define TWO 2	/* ���ϲ��,�����ʹ��ע�� */
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde"	/* һ������ȱ�����������˵����ı���������˹��-������ */
#define FOUR TWO * TWO
#define PX printf("X is %d.\n", x)
#define FMT "X is %d.\n"

int main(int argc, char ** argv)
{
	int x = TWO;

	PX;
	x = FOUR;
	printf(FMT, x);
	printf("%s\n", OW);
	printf("TWO: OW\n");

	return EXIT_SUCCESS;
}
