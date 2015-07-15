/* pe15-3.c -- 测试参数中打开的位的数量 */
#include <stdio.h>
#include <stdlib.h>

#define BYTES 8

char * itobs(int, char *);
int onbits(int);

int main(int argc, char ** argv)
{
	int val;
	char * bsrt = (char *)malloc(sizeof(int) * BYTES + 1);
	
	printf("Enter an integer (negative to quit):");
	while(scanf("%d", &val) && val >= 0){
		printf("%d (%s) has %d bits on.\n", val,
		 itobs(val, bsrt), onbits(val));
		 printf("Next value: ");
	}
	
	free(bsrt);
	fputs("Done!\n", stdout);
	exit(EXIT_SUCCESS);
}

char * itobs(int num, char * ps)
{
	int index;
	static int size = sizeof(int) * BYTES;
	
	for(index = size - 1; index >= 0; index--, num >>= 1)
		*(ps + index) = (01 & num) + '0';
	*(ps + size) = '\0';
	
	return ps;
}

int onbits(int arg)
{
	static int size = sizeof(int) * BYTES;
	int index = size;
	int count = 0;
	
	while(index-- > 0){
		if((arg & 01) == 1)
			count++;
		arg >>= 1;		
	}
	
	return count;
}
