#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	unsigned int count_lower = 0;
	unsigned int count_upper = 0;
	
	while((ch = getchar()) != EOF){
		if(islower(ch))
			count_lower++;
		if(isupper(ch))
			count_upper++;
	}
	printf("lower %u,upper %u",count_lower,count_upper);
	
	return 0;
}