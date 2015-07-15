/* byebye.c -- atexit() ʾ������ */
#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main(int argc, char ** argv)
{
	int n;

	atexit(sign_off);	/* ע��sign_off()���� */
	fputs("Enter an integer: \n", stdout);
	if (scanf("%d", &n) != 1){
		fputs("That's no integer!\n", stdout);
		atexit(too_bad);	/* ע��too_bad()���� */
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