/* put1.c -- ����ӻ��з���ӡһ���ַ� */
#include <stdio.h>
void put1(const char *);
int put2(const char *);

int main(void)
{
	put1("If I'd as much money");
	put1(" as I could spend,\n");
	printf("I count %d characters.\n",
	put2("I never would cry old chairs to mend."));
	
	return 0;
}
void put1(const char * string)/* ����ı�����ַ�  */
{
	while( *string != '\0' )
		putchar(*string++);
}

/* put2.c -- ��ӡһ���ַ�, ��ͳ�������ַ��ĸ��� */
int put2(const char * string)
{
	int count = 0;
	while(*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');	/* ���з���ͳ������ */
	
	return (count);
}
