/*
* pe15-6.c
*	一个简单的菜单程序
*  Created on: 2014年3月10日
*      Author: Mr_Li
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pe15-7.h"	//包括函数声明
//驱动函数
int main(int argc, char ** argv)
{
	unsigned long int pf = 0L;
	showMenu(&pf);
	exit(EXIT_SUCCESS);
}
//显示当前字体信息
void showInformation(unsigned long int flag)
{
	fputs(" ID SIZE ALIGNMENT  B   I   U \n", stdout);
	fprintf(stdout, "%3u %4u %9s %3s %3s %3s\n", 
			flag & IDMASK, 
			(flag & SIMASK) >> 8,
			*(ALG + ((flag & ALMASK) >> 16)), 
			*(TOG + ((flag & BFMASK) >> 18)), 
			*(TOG + ((flag & IFMASK) >> 19)), 
			*(TOG + ((flag & UFMASK) >> 20))
			);
}
//获取正确的选项
char get_let(const char * str)
{
	char ch;

	while (strchr(str, (ch = getchar())) == NULL){
		eatLine();
		printf("Enter a character in the list %s\n", str);
	}
	eatLine();

	return ch;
}
//从一定的返回范围内获取正确的输入 [0,size]
int get_int(int size)
{
	int value;
	char * buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

	while (fgets(buffer, BUFFER_SIZE, stdin)){
		if (sscanf_s(buffer, "%d", &value) != 1){
			fprintf(stderr, "Bad input skipped: %s", buffer);
			continue;
		}
		else if (value < 0 || value > size){
			fprintf(stderr, "%d is not a valid value skipped.\n", value);
			continue;
		}
		else{
			break;
		}
	}
	free(buffer);
	return value;
}
//显示主菜单
void showMenu(unsigned long int * flag)
{
	char choice;

	showStr(*flag);
	while ((choice = get_let("fsabiuq")) != 'q'){
		switch (choice){

		case 'f':change_font(flag);
			break;
		case 's':change_size(flag);
			break;
		case 'a':change_aligment(flag);
			break;
		case 'b':(*flag) ^= (01 << 18);	//转置位
			break;
		case 'i':(*flag) ^= (01 << 19);
			break;
		case 'u':(*flag) ^= (01 << 20);
			break;
		default:
			printf("OH! NO ! The program was wrong.\n");
			exit(EXIT_FAILURE);
		}
		showStr(*flag);
	}

	fprintf(stdout, "Bye!\n");
}

//显示信息
void showStr(unsigned long int flag)
{
	showInformation(flag);
	fprintf(stdout, "%s\n", MSTR);
	fprintf(stdout, "%s\n", MSTR1);
	fprintf(stdout, "%s\n", MSTR2);
}
//改变字体编号
void change_font(unsigned long int * pf)
{
	printf("Enter font ID(0-255):");
	//清除原来设置位
	*pf &= (~IDMASK);
	*pf |= get_int(255);
}
//改变字体大小
void change_size(unsigned long int * pf)
{
	printf("Enter font size(0-127):");
	//清除原来设置的位
	*pf &= (~SIMASK);
	*pf |= (get_int(127) << 8);
}
//改变字体对齐方式
void change_aligment(unsigned long int * pf)
{
	char ch;
	fprintf(stdout, "%s\n", SSTR);
	ch = get_let("lcr");
	//清除原来设置的位
	*pf &= (~ALMASK);
	switch (ch)
	{
	case 'l':*pf |= (0 << 16);
		break;
	case 'c':*pf |= (2 << 16);
		break;
	case 'r':*pf |= (1 << 16);
		break;
	default:fprintf(stderr, "The program was get into trouble.\n");
		break;
	}
}
//清空行缓冲
void eatLine(void)
{
	while (getchar() != '\n')
		continue;
}
