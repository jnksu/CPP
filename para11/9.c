#include <stdio.h>
#define MAX 81

void deleteSpace(char * str);

int main(int argc, char ** argv)
{
	char temp[MAX];
	while(fgets(temp, MAX, stdin))
	{
		fputs(temp, stdout);
		deleteSpace(temp);
		fputs(temp, stdout);
	}
	
	printf("Bye!");
	return 0;
}

void deleteSpace(char * str)
{
	char * temp;
	
	while(*str)
	{
		if(*str == ' '){
			temp = str;
			while(*temp){
				*temp = *(temp + 1);
				temp++;
			}
			
		}
		if(*str != ' ')
			str++;
	}
}
