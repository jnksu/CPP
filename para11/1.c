#include <stdio.h>
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
	char temp;
	int count = 0;
	
	while((temp = getchar()) != EOF && count++ < cou)
		*ch_ptr++ = temp;
	
	*(ch_ptr + count) = '\0';
	
	while(getchar() != '\n')
		continue;
}