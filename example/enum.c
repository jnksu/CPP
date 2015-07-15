/* enum.c -- 使用枚举值 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>		//为了使用strcmp()
#include <stdbool.h>	//C99特性

#define LEN 31

enum spectrum{red, orange, yellow, green, blue, violet};
void reject_ch(char *, int);

const char * colors[] = {
	"red", "orange", "yellow",
	"green", "blue", "violet}"
}; 

int main(int argc, char ** argv)
{
	char * choice = (char *)malloc(LEN * sizeof(char));
	int color;	//可移植性
	bool color_is_found = false;
	
	fputs("Enter a color(empty line to quit): \n", stdout);
	while(fgets(choice, LEN, stdin) && *choice != '\n'){
		reject_ch(choice, '\n');
		for(color = red; color <= violet; color++)
		{
			if(strcmp(choice, *(colors + color)) == 0){
				color_is_found = true;
				break;
			}
		}
		
		if(color_is_found){
			switch(color){
				case red	:fputs("Rose are red.\n", stdout);
							break;
				case orange :fputs("Poppies are orange.\n", stdout);
							break;
				case yellow :fputs("Sunflowers are yellow.\n", stdout);
							break;
				case green  :fputs("Grass is green.\n", stdout);
							break;
				case blue	:fputs("Bluebells are blue.\n", stdout);
							break;
				case violet :fputs("Violets are violet.\n", stdout);
							break;
			}
		}else{
			printf("I don't know about the color %s.\n", choice);
		}
		
		color_is_found = false;
		fputs("Next color, please(empty line to quit): \n", stdout);
	
	}
	
	
	free(choice);
	fputs("Bye~!.\n", stdout);
	exit(EXIT_SUCCESS);
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
