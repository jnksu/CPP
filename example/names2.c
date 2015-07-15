/* names2.c -- 传递和返回结构 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAMELEN 21

struct namect{
	char fname[NAMELEN];
	char lname[NAMELEN];
	int  letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
void reject_ch(char *, int);

int main(int argc, char ** argv)
{
	struct namect person;
	
	person = getinfo();
	person = makeinfo(person);
	showinfo(person);
	
	exit(EXIT_SUCCESS);
}

struct namect getinfo(void)
{
	struct namect temp;
	printf("Please enter your first name.\n");
	fgets(temp.fname, NAMELEN, stdin);
	reject_ch(temp.fname, '\n');
	printf("Please enter your last  name.\n");
	fgets(temp.lname, NAMELEN, stdin);
	reject_ch(temp.lname, '\n');
	
	return temp;
}

struct namect makeinfo(struct namect info)
{
	info.letters = strlen(info.fname) + strlen(info.lname);
	return info;
}

void showinfo(struct namect info)
{
	printf("%s %s, your name contains %d letters.\n", 
		info.fname, info.lname, info.letters);
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}

