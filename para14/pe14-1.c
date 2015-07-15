/* pe14-1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRLEN 5

struct month{
	char name[10];
	char abbrev[4];
	int days;
	int monumb;
};

const struct month months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}	
};

int days(char * arg);
void  reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	char * in = (char *)malloc(STRLEN * sizeof(char));
	int day_total;
	
	fputs("Enter the name of a month: ", stdout);
	
	while(fgets(in, STRLEN, stdin) && *in != '\n'){
		reject_ch(in, '\n');
		
		day_total = days(in);
		
		if(day_total > 0){
			printf("The are %d days through %s.\n", day_total, in);
		}else{
			printf("%s is not valid input.\n", in);
		}
		
		printf("Next month(empty line to quit): ");
	}
	
	free(in);
	printf("Bye~!\n");
	exit(EXIT_FAILURE);
}

int days(char * arg)
{
	int index;
	int total = 0;
	int mon_num = -1;
	
	if(*arg == '\0')
		return -1;
	else{
		*arg = toupper(*arg);	
		
		for(index = 1; *(arg + index) != '\0'; index++)
			*(arg + index) = tolower(*(arg + index));
	
		for(index = 0; index < 12; index++){
			if(strcmp(arg, months[index].abbrev) == 0){
				mon_num = index;
				break;
			}
		}
		
		if(mon_num < 0)		
			return -1;
		else
			for(index = 0; index <= mon_num; index++)
				total += months[index].days;
	}
	
	return total;
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
