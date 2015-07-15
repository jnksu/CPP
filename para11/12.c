#include <stdio.h>

int main(int argc, char ** argv)
{
	while(argc > 1){
	fputs(*(argv + (argc - 1)), stdout);
	printf(" ");
	argc--;
	}
	
	return 0;
}