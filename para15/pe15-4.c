/* pe15-4.c -- 测试参数特定的位是否打开 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BYTES 8

bool exitBit(int, int);
char * itobs(int, char *);
void showBit(const char *);

int main(int argc, char ** argv)
{
	int val, pos;
	char * bstr = (char *)malloc(sizeof(int) * BYTES + 1);
	
	printf("Enter two integer (negative to quit):");
	while(scanf("%d %d", &val, &pos) == 2 && val >= 0 && pos >= 0){
		itobs(val, bstr);
		printf("%d has", val);
		showBit(bstr);
		putchar('\n');
		printf("%d position %d exit:", val, pos);
		printf("%d\n", exitBit(val, pos));
		
		printf("Next value:");
	}
	
	free(bstr);
	printf("Bye~!\n");
	exit(EXIT_SUCCESS);
}

bool exitBit(int val, int pos)
{
	static int size = sizeof(int) * BYTES;
	int index;
	//参数合法性
	if(pos <= 0 || pos > size){
		fprintf(stderr, "The argument position Wrong!\n");
		exit(EXIT_SUCCESS);
	}
	
	for(index = 0; index < pos - 1; index++)
		val >>= 1;
		
	if((val & 01) == 1)
		return true;
	else
		return false;
}

char * itobs(int num, char * ps)
{
	static int size = sizeof(int) * BYTES;
	int index;
	
	for(index = size - 1; index >= 0; index--, num >>= 1)
		*(ps + index) = (num & 01) + '0';
	*(ps + size) = '\0';

	return ps;
}

void showBit(const char * ps)
{
	int count = 0;
	
	while(*ps){
		putchar(*ps++);
		if(++count % 4 == 0 && ps)
			putchar(' ');
	}
}
