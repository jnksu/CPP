/* r_drive0.c -- ����rand0() ���� */
/* ��rand0.c һ����� */
#include <stdio.h>
extern int rand0(void);

int main(int argc, char ** argv)
{
	int count;
	
	for(count = 0; count < 5; count++)
		printf("%hd\n", rand0());
	return 0;
}
