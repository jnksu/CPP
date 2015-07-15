/*loccheck.c -- 查看变量的存储地址*/
#include <stdio.h>

void mikado(int);

int main(void)
{
	int pooh = 2;
	int bah = 5;
	
	printf("In main(),pooh = %d and &pooh = %p\n",
				pooh,&pooh);
	printf("In main(),ban = %d and &bah = %p\n",
				bah,&bah);
	mikado(pooh);
		
	return 0;
}

void mikado(int bah)
{
	int pooh = 10;
	
	printf("In mikado(),pooh = %d and &pooh = %p\n",
				pooh,&pooh);
	printf("In mikado(),bah = %d and &bah = %p\n",
				bah,&bah);
}