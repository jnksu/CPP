/* startch.c -- Ê¹ÓÃstrncmp()º¯Êý */
#include <stdio.h>
#include <string.h>
#define LISTSIZE 5

int main(void)
{
	char * list[LISTSIZE] = {
		"astronomy",
		"astounding",
		"astrophysics",
		"ostracize",
		"asterism",
	};
	int count = 0;
	int index;
	
	for(index = 0;index < LISTSIZE; index++){
		if(strncmp(LIST[index], "astro", 5) == 0)
		{
			printf("Found: %s\n", list[index]);
			count++;
		}
	}
	printf("The list contained %d words beginning"
			" with astro.\n", count);
	
	return 0;
}