/* global.c -- 使用外部变量 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	int units = 0;
	
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while(units != 56){
		printf("No luck chummy. Try agian.\n");
		scanf("%d", &units);
	}
	
	printf("You must have looked it up!\n");
	exit(EXIT_SUCCESS);
}