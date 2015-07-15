/* byebye.c -- atexit() Ê¾Àý³ÌÐò */
#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main(int argc, char ** argv)
{
	int n;

	atexit(sign_off);	/* ×¢²ásign_off()º¯Êý */
	fputs("Enter an integer: \n", stdout);
	if (scanf("%d", &n) != 1){
		fputs("That's no integer!\n", stdout);
		atexit(too_bad);	/* ×¢²átoo_bad()º¯Êý */
		exit(EXIT_FAILURE);
	}
	printf("%d is %s.\n", n, (n % 2 == 0) ? "even": "odd");
	return EXIT_SUCCESS;
}

void sign_off(void)
{
	fputs("Thus terminates abother magnificent program from", stdout);
	fputs("SeeSaw Software\n", stdout);
}

void too_bad(void)
{
	fputs("Seesaw Software extends its heartfelt condolences", stdout);
	fputs("to you upon the failure of your program\n", stdout);
}