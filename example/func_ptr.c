// func_ptr.c -- 使用函数指针 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRLEN 81

char showmenu(void);
void eatline(void);		//读至行末
void show(void (* fp)(char *), char * str);
void Toupper(char *);	//把字符串转换为大写
void ToLower(char *);	//把字符串转换为小写
void Transpose(char *); //大小写转换
void Dummy(char *);		//不改变字符串
void  reject_ch(char * str, int ch);	//从字符串中剔除特定的字符

int main(int argc, char ** argv)
{
	char line[STRLEN];
	char copy[STRLEN];
	char choice;
	void (* pfun)(char *);		//指向一个函数, 该函数接受
								//一个char * 参数, 并且
								//没有返回值
	fputs("Enter a string(empty line to quit): \n", stdout);
	while(fgets(line, STRLEN, stdin) && *line != '\n'){
		reject_ch(line, '\n');
		
		while((choice = showmenu()) != 'n')
		{
			//switch 语句用来设置指针
			switch(choice){
				case 'u': pfun = Toupper;
						break;
				case 'l': pfun = ToLower; 
						break;
				case 't': pfun = Transpose;	
						break;
				case 'o': pfun = Dummy; 
						break;
			}
			strcpy(copy, line); //为show()制作一份拷贝
			show(pfun, copy);
		}
		fputs("Enter a string(empty line to quit): \n", stdout);
	}
	
	fputs("Bye~!\n", stdout);
	exit(EXIT_SUCCESS);
}

char showmenu(void)
{
	char ans;
	fputs("Enter the choice: \n", stdout);
	fputs("u)upper case         l)lower case\n", stdout);
	fputs("t)transposed case    o)original case\n", stdout);
	fputs("n)next string\n", stdout);
	ans = getchar();			//获取用户响应
	ans = tolower(ans);			//转换为小写
	eatline();					//剔除用户输入缓冲中的剩余部分
	while(strchr("ulton", ans) == NULL){
		fputs("Please enter a u, l, t, o, or n:\n", stdout);
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void)
{
	while(getchar() != '\n')
		continue;
}

void Toupper(char * str)
{
	while(*str){
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char * str)
{
	while(*str){
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char * str)
{
	while(*str){
		if(islower(*str))
			*str = toupper(*str);
		else if(isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char * str)
{
	//不改变字符串
}

void show(void (* fp)(char *), char * str)
{
	(*fp)(str);	//把用户选择的函数作用于str
	fprintf(stdout, "%s\n", str);//显示结果
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
