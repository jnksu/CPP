#include <stdio.h>
int count(void);

int main(int argc, char ** argv)
{
	int i;
	
	for(i = 0; i < 100; i++)
		printf("%d\n", count());
	return 0;
}

int count(void)
{
	static int used = 0;
	used++;
	
	return used;
}
