/* hello.c -- 把命令行参数转换为数字 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	int index, times;
	
	if( argc < 2 || (times = atoi(*(argv + 1))) < 1)
		printf("Usage: %s positive-number\n", argv[0]);
	else
		for(index = 0; index < times; index++)
			puts("Hello, good looking!");
			
	return 0;
}

