#include <stdio.h>
#include <ctype.h>
#define MAX 81

void dis_ch(char * ch_ptr, int cou);

int main(int argc, char ** argv)
{
	char temp[MAX];
	dis_ch(temp, 10);
	
	puts(temp);
	return 0;
}

void dis_ch(char * ch_ptr, int cou)
{
	int index;
	char temp;
	
	for(index = 0; index < cou; index++)
	{
		temp = getchar();
		if(isspace(temp) || temp == EOF){
			*(ch_ptr + index) = '\0';
			return;
		}
		*(ch_ptr + index) = temp;
	}
	*(ch_ptr + index) = '\0';
	
	while(getchar() != EOF)
		continue;
}
