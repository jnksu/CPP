/* name1.c -- ��ȡһ������ */
#include <stdio.h>

#define MAX 81

int main(void)
{
	char name[MAX];		/*����ռ�				*/
	printf("Hi, what's your name?\n");
	gets(name);			/*���ַ����Ž�name������*/
	printf("Nice name, %s.\n", name);
	return 0;
}