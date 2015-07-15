/* pe14-4.c -- 显示个人信息 */
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

void shin(PEOPLE * ptr, int size);

void shin(PEOPLE * ptr, int size)
{
	int index;
	
	for(index = 0; index < size; index++){
		
		if(strlen((ptr + index)->names.mname) != 0){
			printf("%10s, %10s %c. - %lu\n", (ptr + index)->names.fname, 
				(ptr + index)->names.lname, toupper(ptr[index].names.mname[0]), 
					(ptr + index)->ssn);
		}else{
			printf("%10s, %10s    - %lu\n", (ptr + index)->names.fname, 
				(ptr + index)->names.lname, (ptr + index)->ssn);
		}
	}
}

int main(int argc, char ** argv)
{
	PEOPLE pa[5] = {
		{302039823,{"Dribble",  "M", "Flossie"}},
		{302039824,{"Rtigith",  "",  "Twsdloa"}},
		{302039825,{"Gonzalez", "H", "Harris" }},
		{302039826,{"Louis",    "D", "Armstrong"}},
		{302039827,{"Alphonse", "A", "Roberts"}}
	};
	
	shin(pa, 5);
	
	exit(EXIT_SUCCESS);
}
