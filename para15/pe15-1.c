/* pe15-1.c -- 将二进制转换为十进制 */
#include <stdio.h>
#include <stdlib.h>

#define BYTES BYTES
int strConverDig(const char *);

int main(int argc, char ** argv)
{
	printf("%d", strConverDig("0101"));
	exit(EXIT_SUCCESS);
}

int strConverDig(const char * str)
{
	//检查参数合法性
	int len = 0;
	int index;
	int val = 0;
	
	len = strlen(str);
	if(len = 0 || len > (sizeof(int) * BYTES))
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
