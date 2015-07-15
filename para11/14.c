#include <stdio.h>
#include <ctype.h>
#define LIM 5
#define MAXCH 81

int atoi_c(const char * nptr);

int main(int argc, char ** argv)
{
	int con;
	char temp[MAXCH];
	
	while(fgets(temp, MAXCH, stdin)){
		con = atoi_c(temp);
		printf("The result is:%d\n", con);
	}
	printf("Bye!\n");
	return 0;
}

int atoi_c(const char * nptr)
{
	int con = 0;
	int count = 0;
	int index;
	int nest;
	int temp[LIM] = {0, 0, 0, 0, 0};
	const char * str = nptr;
	
	while(*str && isspace(*str))
		str++;
	while(*str && isdigit(*str) && count < LIM){
		switch(*str)
		{
			case '0':   temp[count++] = 0;
						break;
			case '1':	temp[count++] = 1;
						break;
			case '2':	temp[count++] = 2;
						break;
			case '3':	temp[count++] = 3;
						break;
			case '4':	temp[count++] = 4;
						break;
			case '5':	temp[count++] = 5;
						break;
			case '6':	temp[count++] = 6;
						break;
			case '7':	temp[count++] = 7;
						break;
			case '8':	temp[count++] = 8;
						break;
			case '9':	temp[count++] = 9;
						break;
			default:printf("Program Error!");
						break;
		}
		str++;
	}
	
	for(index = 0; index < count; index++)
	{
		for(nest = 1; nest < (count - index); nest++)
			temp[index] *= 10;
	}
	
	for(index = 0; index < count; index++)
	{
		con += temp[index];
	}
	
	return con;
}
