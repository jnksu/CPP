#include <stdio.h>
#include <ctype.h>
#define LIM 81 
void show_mes(char * str);

int main(int argc, char ** argv)
{
	char temp[LIM];
	
	while(fgets(temp, LIM, stdin)){
		show_mes(temp);
	}
	
	printf("Bye!\n");
	return 0;
}

void show_mes(char * str)
{
	int words = 0;
	int catipal = 0;
	int lower = 0;
	int punct = 0;
	int num = 0;
	char prev = ' ';
	
	while(*str)
	{
		if(!isalpha(prev) && isalpha(*str))
			words++;
		if(isupper(*str))
			catipal++;
		if(islower(*str))
			lower++;
		if(ispunct(*str))
			punct++;
		if(isdigit(*str))
			num++;
		prev = *str;
		str++;
	}
	printf("The words: %4d, the upper: %4d, the lower: %4d, the punct %4d, the digit %4d\n",
			words, catipal, lower, punct, num);
}



