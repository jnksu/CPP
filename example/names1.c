/* names1.c --  使用指向结构的指针 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMELEN 21

struct namect{
	char fname[NAMELEN];
	char lname[NAMELEN];
	int letterts;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *); 
void reject_ch(char *, int);

int main(int argc, char ** argv)
{
	struct namect person;
	
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	
	exit(EXIT_SUCCESS);
}

void getinfo(struct namect * pst)
{
	printf("Please enter your first name.\n");
	fgets(pst->fname, NAMELEN, stdin);
	reject_ch(pst->fname, '\n');
	printf("Please enter your last name.\n");
	fgets(pst->lname, NAMELEN, stdin);
	reject_ch(pst->lname, '\n');
}

void makeinfo(struct namect * pst)
{	
	pst->letterts = strlen(pst->fname) +
					strlen(pst->lname);
					
}

void showinfo(const struct namect * pst)
{
	printf("%s %s, your name contains %d letters.\n",
		pst->fname, pst->lname, pst->letterts);
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
