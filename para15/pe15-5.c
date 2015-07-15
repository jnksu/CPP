/* pe15-5.c -- 循环移位函数 */
#include <stdio.h>
#include <stdlib.h>

#define BYTES 8

char * itobs(int, char *);
int rotate(unsigned int, int);
 
int main(int argc, char ** argv)
{
	unsigned int val;
	unsigned int rot;
	unsigned int places;
	char * bstr = (char *)malloc(sizeof(int) * BYTES + 1);
	char * bstr1 = (char *)malloc(sizeof(int) *BYTES + 1);
	
	printf("Enter an integer (0 to quit)L ");
	while(scanf("%ud", &val) && val > 0)
	{
		printf("Enter the number of bits to be rotated: \n");
		scanf("%ul", &places);
		rot = rotate(val, places);
		itobs(val, bstr);
		itobs(rot, bstr1);
		printf("%u rotated is %u.\n", val, rot);
		printf("%s rotated is %s.\n", bstr, bstr1);
		printf("Next value");
	}
	
	free(bstr);
	free(bstr1);
	printf("Bye~!\n");
	exit(EXIT_SUCCESS);
}

int rotate(unsigned int num, int pos)
{
	static int size = sizeof(unsigned int) * BYTES;
	unsigned int mask = 1; // 掩码
	unsigned int overflow = 0;
	int index;
	
	//检查参数合法性
	if(pos <= 0 || pos > size){
		fprintf(stderr, "The argument position Wrong!\n");
		exit(EXIT_SUCCESS);
	}
	else{
		//设置掩码
		for(index = 0; index < pos - 1; index++){
			mask <<= 1;
			mask |= 1;
		}
		//取出要循环的位
		overflow = num & mask;
		//循环的位移动至高位
		overflow <<= (size - pos);
		//移动参数
		num   >>= pos;
		//计算移位后的值
		num |= overflow;
	}
	
	return num;
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
