/* pe15-2.c -- 对命令行参数进行位运算 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BYTES 8

int strConDig(const char *);
char * itobs(int, char *);
void showStr(const char *);
void showStrBin(int, char *, const char *);

int main(int argc, char ** argv)
{
	//检查参数的合法性
	if( argc != 3){
		fprintf(stderr, "Usage: %s positive-number positive-number\n", *(argv));
		exit(EXIT_FAILURE);
	}else{
		int arg,arg1;
		char * str = (char *)malloc(sizeof(int) * BYTES + 1);
		
		arg  = strConDig(*(argv + 1));//获取第一个参数
		arg1 = strConDig(*(argv + 2));//获取第二个参数
		
		//原始
		showStrBin(arg, str, "arg");
		showStrBin(arg1, str, "arg1");
		//取反
		printf("~\n");
		showStrBin(~arg, str, "arg");
		showStrBin(~arg1, str, "arg1");
		//取与
		printf("&\n");
		showStrBin(arg & arg1, str, "arg & arg1");
		//取或
		printf("|\n");
		showStrBin(arg | arg1, str, "arg | arg1");
		//取异或
		printf("^\n");
		showStrBin(arg ^ arg1, str, "arg ^ arg1");
		
		free(str);
	}
	
	exit(EXIT_SUCCESS);
}

int strConDig(const char * str)
{
	//检查合法性
	int len = 0;
	int index;
	int val = 0;
	len = strlen(str);
	
	if(len == 0 || len > (sizeof(int) * BYTES))
		return -1;
	else{
		for(index = 0; index < len; index++){
			val <<= 1;
			if(*(str + index) == '1')
				val |= 1;
		}
	}
	
	return val;
}

char * itobs(int num, char * str)
{
	static int size = sizeof(int) * BYTES;	//一个缺省整型的位数
	int index = size;
	
	while(index-- > 0){
		*(str + index) = (num & 01) + '0';
		num >>= 1;
	}
	*(str + size) = '\0';
	
	return str;
}

void showStr(const char * str)
{
	int index = 0;
	
	while(*str){
		putchar(*(str++));
		
		if(++index % 4 == 0 && *str)
			putchar(' ');
	}
}

void showStrBin(int num, char * str, const char * show)
{
	itobs(num, str);
	printf("%10s:", show);
	showStr(str);
	putchar('\n');
}
