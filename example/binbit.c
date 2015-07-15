/* binbit.c -- 使用位运算显示二进制数 */
#include <stdio.h>
#include <stdlib.h>
#define	 BIT 8

char * itobs(int, char *);
void show_bstr(const char *);

int main(int argc, char ** argv)
{
	char * bin_str = (char *)malloc(BIT * sizeof(int) + 1);
	int number;
	
	fputs("Enter integer and see them in binary.\n", stdout);
	fputs("Non-numeric input terminates program.\n", stdout);
	while(scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d is ", number);
		show_bstr(bin_str);
		putchar('\n');
	}
	
	free(bin_str);
	fputs("Bye!\n", stdout);
	
	exit(EXIT_SUCCESS);
}

char * itobs(int num, char * str)
{
	static int size = sizeof(int) * BIT;
	int index;	
	
	for(index = size - 1; index >= 0; num >>= 1, index--)
		*(str + index) = (num & 01) + '0';
	
	*(str + size) = '\0';
	
	return str;
}

void show_bstr(const char * str)
{
	int index = 0;
	
	while(*(str + index)){
		putchar(*(str + index));
		
		if(++index % 4 == 0 && *(str + index))	//最后一个空格不会输出
			putchar(' ');
	}
}
