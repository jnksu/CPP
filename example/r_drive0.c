/* r_drive0.c -- 测试rand0() 函数 */
/* 与rand0.c 一起编译 */
#include <stdio.h>
extern int rand0(void);

int main(int argc, char ** argv)
{
	int count;
	
	for(count = 0; count < 5; count++)
		printf("%hd\n", rand0());
	return 0;
}
