/* global.c -- ʹ���ⲿ���� */
#include <stdio.h>
int units = 0;		/*һ���ⲿ����*/
void critic(void);
int main(int argc, char ** argv)
{
	extern int units;	/*��ѡ�Ķ�������*/
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while(units != 56)
		critic();
	printf("You must look it up!\n");	
	return 0;
}

void critic(void)
{
	/*����ʡ���˿�ѡ�Ķ�������*/
	printf("No luck, chummy. Try again.\n");
	scanf("%d", &units);
	
}
