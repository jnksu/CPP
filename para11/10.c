#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXCH 81
#define MAXSTR 10
#define TIE	 "Enter the number of your choice:"
#define STR  "1)Print the original list of strings."
#define STR1 "2)print the strings in ASCII collating."
#define STR2 "3)print the strings in order of increasing length."
#define STR3 "4)print the strings in order of the length of the first word in the string."
#define STR4 "5)Quit!"

char getChoice(void);
char getFirst(void);
void show_str(int size, char ** str);
void sort_str(int size, char ** str);
void show_str_asc(int size, char ** str);
void show_str_word_asc(int size, char ** str);
void show_arr(char (*str)[MAXCH], int size);

int main(int argc, char ** argv)
{
	char * input_ptr[MAXSTR];
	char input[MAXSTR][MAXCH];
	int choice;
	int count = 0;
	int totStr;
	
	printf("Input up %d lines, and I will sort them.\n", MAXSTR);
	printf("To stop, press the Enter key at a line's start.\n");
	
	while(count < MAXSTR && 
			fgets(input[count], MAXCH, stdin) != NULL && 
				input[count][0] != '\n'){
				
			input_ptr[count] = input[count];
			count++;
	}
	
	totStr = count;
	
	/*初始化剩余数组*/
	while(count < MAXSTR){
		input[count][0] = '\0';
		input_ptr[count] = input[count];
		count++;
	}
	
	while(( choice = getChoice()) != '5')
	{
		switch(choice)
		{
			case '1':show_arr(input, MAXSTR);
						break;
			case '2':sort_str(totStr, input_ptr);
					 show_str(MAXSTR, input_ptr);
						break;
			case '3':show_str_asc(totStr, input_ptr);
					 show_str(MAXSTR, input_ptr);
						break;
			case '4':show_str_word_asc(totStr, input_ptr);
					 show_str(MAXSTR, input_ptr);
						break;
			
			default :printf("Program error!\n");
					break;
		}
	}
	printf("Bye!\n");
	return 0;
}

char getChoice(void)
{
	int temp;
	
	printf("%s\n", TIE);
	printf("%s\n", STR);
	printf("%s\n", STR1);
	printf("%s\n", STR2);
	printf("%s\n", STR3);
	printf("%s\n:", STR4);
	
	while((temp = getFirst()) > '5' || temp < '1')
		printf("Please respond with 1,2,3,4 or 5.\n:");
		
	return temp;
}

char getFirst(void)
{
	char temp;
	
	temp = getchar();
	
	while(getchar() != '\n')
		continue;
	
	return temp;
}

void show_str(int size, char ** str)
{
	int index;
	
	for(index = 0; index < size; index++)
	{
		printf("%d:", index + 1);
		if(**(str + index))
			fputs(*(str + index), stdout);
		else
			printf("NULL.\n");
	}
}

void sort_str(int size, char ** str)
{
	int index,nest;
	char * temp;
	
	for(index = 0; index < size - 1; index++)
	{
		for(nest = index + 1; nest < size; nest++){
			if((strncmp(*(str + index), *(str + nest), 1)) > 0)
			{
				temp = *(str + index);
				*(str + index) = *(str + nest);
				*(str + nest) = temp;
			}
		}
	}
}

void show_str_asc(int size, char ** str)
{
	int index,nest;
	char * temp;
	
	for(index = 0; index < size - 1; index++){
		for(nest = index + 1; nest < size; nest++)
		{
				if(strlen(*(str + index)) > strlen(*(str + nest))){
					temp = *(str + index);
					*(str + index) = *(str + nest);
					*(str + nest) = temp;
				}
		}
	}
}

void show_str_word_asc(int size, char ** str)
{
	int len[MAXSTR];
	int index,nest;
	int count = 0;
	char * temp;
	
	for(index = 0; index < size; index++)
	{
		temp = *(str + index);
		
		while(*temp && !isalpha(*temp))
			temp++;
		while(*temp && isalpha(*temp)){
			count++;
			temp++;
		}
		len[index] = count;
		count = 0;
	}
	
	for(index = 0; index < size - 1; index++)
	{
		for(nest = index + 1; nest < size; nest++){
				if(len[index] > len[nest])
				{
					len[index] ^= len[nest];
					len[nest]  ^= len[index];
					len[index] ^= len[nest];
					
					temp = *(str + index);
					*(str + index) = *(str + nest);
					*(str + nest)  = temp;
				}
		}
	}
}

void show_arr(char (*str)[MAXCH], int size)
{
	int index;
	
	for(index = 0; index < size; index++)
	{
		printf("%d:", index + 1);
		if(**(str + index))
			fputs(*(str + index), stdout);
		else
			printf("NULL\n");
	}
}
