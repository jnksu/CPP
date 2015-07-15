/* put1.c -- 不添加换行符打印一个字符 */
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
void put1(const char * string)/* 不会改变这个字符  */
{
	while( *string != '\0' )
		putchar(*string++);
}

/* put2.c -- 打印一个字符, 并统计其中字符的个数 */
int put2(const char * string)
{
	int count = 0;
	while(*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');	/* 换行符不统计在内 */
	
	return (count);
}
