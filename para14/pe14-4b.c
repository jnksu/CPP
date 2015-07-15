/* pe14-4b.c -- 显示个人信息 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define  SNML 31
 
struct name{
	char fname[SNML];
	char mname[SNML];
	char lname[SNML];
};

typedef struct{
	unsigned long int ssn;
	struct name names;
} PEOPLE;

void shin(PEOPLE ptr);

void shin(PEOPLE ptr)
{
		
		if(strlen(ptr.names.mname) != 0){
			printf("%10s, %10s %c. - %lu\n", ptr.names.fname, 
				ptr.names.lname, toupper(ptr.names.mname[0]), 
					ptr.ssn);
		}else{
			printf("%10s, %10s    - %lu\n", ptr.names.fname, 
				ptr.names.lname, ptr.ssn);
		}
}

int main(int argc, char ** argv)
{
	int index;
	
	PEOPLE pa[5] = {
		{302039823,{"Dribble",  "M", "Flossie"}},
		{302039824,{"Rtigith",  "",  "Twsdloa"}},
		{302039825,{"Gonzalez", "H", "Harris" }},
		{302039826,{"Louis",    "D", "Armstrong"}},
		{302039827,{"Alphonse", "A", "Roberts"}}
	};
	for(index = 0; index < 5; index++)
		shin(pa[index]);
	
	exit(EXIT_SUCCESS);
}
