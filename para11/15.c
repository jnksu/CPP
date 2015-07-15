#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 81

int main(int argc, char ** argv)
{
	char * temp;
	char * rear;
	char in_str[LIM];
	
	while(fgets(in_str, LIM, stdin))
	{
		rear = in_str;
	
		if(argc == 2){
			temp = *(argv + 1);
			if(strcmp(temp , "-p") == 0)
				fputs(in_str, stdout);
			if(strcmp(temp,  "-u") == 0){
				while(*rear)
				{
					*rear = toupper(*rear);
					rear++;
				}
				fputs(in_str, stdout);
			}
			if(strcmp(temp,  "-l") == 0){
				while(*rear)
				{
					*rear = tolower(*rear);
					rear++;
				}
				fputs(in_str, stdout);
			}
		}
	}
	
	printf("Bye!");
	return 0;
}
