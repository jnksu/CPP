/* invert4.c -- 使用位操作来显示二进制 */
#include <stdio.h>
#include <stdlib.h>
#define BYTESBIT 8

char * itobs(int, char *);
void show_bstr(const char *);
int invert_end(int, int);

int main(int argc, char ** argv)
{
	char * bin_str = (char *)malloc(sizeof(int) * BYTESBIT + 1);
	int number;
	
	fputs("Enter integer and see them in binary.\n", stdout);
	fputs("Non-numeric input terminates program.\n", stdout);
	
	while(scanf("%d", &number) == 1){
		itobs(number, bin_str);
		printf("%d is\n", number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Inverting the last 4 bits gives\n");
		show_bstr(itobs(number, bin_str));
		putchar('\n');
	}
	
	free(bin_str);
	exit(EXIT_SUCCESS);
}

char * itobs(int num, char * ps)
{
	int index;
	static int size = sizeof(int) * BYTESBIT;
	
	for(index = size - 1; size >= 0; index--, num >>= 1)
		*(ps + index) = (01 & num) + '0';
	*(ps + size) = '\0';
	
	return ps;
}

/* 4位一组显示二进制字符串 */
void show_bstr(const char * ps)
{
	int index = 0;
	
	while(*(ps + index) != '\0'){
		putchar(*(ps + index));
		if( ++index % 4 == 0 && *(str + index))
			putchar(' ');
	}	
}

int invert_end(int num, int bits)
{
	int mask = 0;
	int bitval = 1;
	
	while(bits-- > 0){
		mask |= bitval;
		bitval <<= 1;	
	}

	return num ^= mask;	
}
