/*用指向函数的指针执行菜单 -- pe14-10.c*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void foo(void);
void foo1(void);
void foo2(void);
void foo3(void);
void show(void);
void eatLine(void);

typedef void (* VP)(void);

char getLet(const char *);

int main(int argc, char ** argv)
{
	VP fpp[4] = {foo, foo1, foo2, foo3};
	char choice;

	show();
	while((choice = getLet("abcdq")) != 'q'){
		switch(choice){
			case 'a':(*fpp[0])();
						break;
			case 'b':(*fpp[1])();
						break;
			case 'c':(*fpp[2])();
						break;
			case 'd':(*fpp[3])();
						break;
		}
		show();
	}

	fprintf(stdout, "%s\n", "Bye~!");
	exit(EXIT_SUCCESS);
}
//刷新行缓冲
void eatLine(void)
{
	while(getchar() != '\n')
		continue;	
}
//获取正确的菜单选项
char getLet(const char * str)
{
	char ch;

	ch = getchar();
	while(!strchr(str, ch)){
		fprintf(stderr, "Enter a character in the list %s\n", str);
		eatLine();
	ch = getchar();	
	}
	eatLine();

	return ch;
}
void foo(void){putchar('a');}
void foo1(void){putchar('b');}
void foo2(void){putchar('c');}
void foo3(void){putchar('d');}
//显示界面
void show(void)
{
	fputs("To choose a function, entert its letter label:\n", stdout);
	fputs("a) foo	b)foo1\n", stdout);
	fputs("c) foo2	d)foo3\n", stdout);
	fputs("q) Quit\n", stdout);
}
