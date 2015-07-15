/* preproc.c 简单的预处理例子 */
#include <stdio.h>
#include <stdlib.h>
#define TWO 2	/* 如果喜欢,你可以使用注释 */
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde"	/* 一致性是缺乏想象力的人的最后的避难所。奥斯卡-怀尔德 */
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
