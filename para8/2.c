#include <stdio.h>

int main(void)
{
	int ch;
	unsigned int count = 1;
	
	while((ch = getchar()) != EOF){
		if(ch < ' ')
		{
			if(ch == '\n')
				printf("\\n %d ",ch);
			else if(ch == '\t')
				printf("\\t %d ",ch);
			else
				printf( "^%c %d ",ch + 64,ch);
		}
		else
			printf("%c %d ",ch,ch);
		if( (count++ % 10) == 0 )
			putchar('\n');
	}
	return 0;
}