#include <stdio.h>
#include <ctype.h>

char * getWord(char * ptr, int size);

int main(void)
{
	char temp[10];
	getWord(temp, 10);
	puts(temp);
	return 0;
}

char * getWord(char * ptr, int size)
{
	char temp;
	int index;
	
	while(isspace(temp = getchar()))
		continue;
	if(temp == EOF){
		*ptr = '\0';
		return NULL;
	}
	else
	{
		*ptr++ = temp;
		for(index = 0; index < size - 1; index++){
			temp = getchar();
			if(temp == EOF || isspace(temp))
				break;
			*ptr++ = temp;
		}
		*ptr = '\0';
		while(getchar() != EOF)
			continue;
		return ptr;
	}
}
