#include <stdio.h>
#define MAX 81

char * string_in(char * target, char * source);

int main(int argc, char ** argv)
{
	char temp[] = "mr_li";
	char temp1[MAX];
	char * ptr;
	
	while(fgets(temp1, MAX, stdin)){
		ptr = string_in(temp1, temp);
		if(ptr)
			fputs(ptr, stdout);
		else
			printf("Failed");
		putchar('\n');
	}
	
	printf("Bye!");
	return 0;
}

char * string_in(char * target, char * source)
{
	char * temp = NULL;
	
	while( *target && *source )
	{
		if(*target++ == *source){
			if(temp == NULL)
				temp = target - 1;
			source++;
		}
			
	}
	
	return	*source ? NULL : temp; 
}

