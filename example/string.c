/* string.c -- ʹ���ַ������û����� */
#include <stdio.h>
#define MSG "You must have many talents. Tell me some. "	//һ���ַ�������
#define LIM 5
#define LINELEN 81											//����ַ������� + 1

int main(void)
{
	char name[LINELEN];
	char talents[LINELEN];
	
	int count;
	//��ʼ��һ����С�Ѿ�ȷ����char����
	const char m1[40] = "Limit yourself to one line's worth. ";
	//�ñ��������������С
	const char m2[] = "If you can't think of anything, fake it. ";
	//��ʼ��һ��ָ��
	const char * m3 = "\nEnough about me - what's your name? ";
	//��ʼ��һ���ַ���ָ������ 
	const char * mytal[LIM] = {
				"Adding numbers swiftly",
				"Multiplying accurately",
				"Stashing data",
				"Following instruction to the letter",
				"Understanding the C language"
	};
	
	printf("Hi! I'm Clyde the computer." 
	" I have many talents.\n");
	printf("Let me tell you some of them.\n");
	puts("What were they? Ah, yes, here's partial list. ");
	
	for(count = 0; count < LIM; count++)
		puts(mytal[count]);
	puts(m3);
	gets(name);
	printf("Well, %s %s\n", name, MSG);
	printf("%s\n%s\n", m1, m2);
	gets(talents);
	puts("Let's see if I've got that list: ");
	puts(talents);
	printf("Thanks for the information, %s.\n", name);
	
	return 0;
}
