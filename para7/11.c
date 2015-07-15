#include <stdio.h>

#define KOREA  	1.25f				//����
#define BEET   	0.65f				//���
#define CARROT 	0.89f				//���Ჷ
#define BASE   	100					//�ۿ�
#define REBATE 	0.05f				//�ۿ۱���
#define WEIGHT 	5					//��һ����������
#define WCOST  	3.50f				//��һ�׷���
#define WEIGHT1	20					//�ڶ�����������
#define WCOST1	10.00f				//�ڶ��׷���
#define WCOST2	8					//������������
#define WCOST3	0.1					//�����׷���
/*��ʾ���ַ���*/
#define TEXT  "*****************************************************************"
#define TEXT1 "Enter the letter corresponding to the desired pay rate or action:"
#define TEXT2 "a)KOREA    b)BEET"
#define TEXT3 "c)CARROT   q)quit"

int main(void)
{
	char options;
	float korea_pound = 0;
	float beet_pound = 0;
	float carrot_pound = 0;
	float sum_cost = 0;
	float sum_pound = 0;
	float rebate = 0;
	float transport_cost = 0;
	
	printf( "%s\n",TEXT );
	printf( "%s\n",TEXT1 );
	printf( "%s\n",TEXT2 );
	printf( "%s\n",TEXT3 );
	printf( "%s\n:",TEXT );
	
	while( (options = getchar()) != 'q' ){	
		switch( options )
		{
			case 'a':
					printf( "Please input pounds:" );
					scanf( "%f",&korea_pound );
					getchar();
					break;
			case 'b':
					printf( "Please input pounds:" );
					scanf( "%f",&beet_pound );
					getchar();
					break;
			case 'c':
					printf( "Please input pounds:" );
					scanf( "%f",&carrot_pound );
					getchar();
					break;
			default:
					printf( "Please input correct values!\n" );
					getchar();
		}
			printf( "%s\n",TEXT );
			printf( "%s\n",TEXT1 );
			printf( "%s\n",TEXT2 );
			printf( "%s\n",TEXT3 );
			printf( "%s\n:",TEXT );
	}
	
	//�����ܷ���
	sum_cost = korea_pound * KOREA + beet_pound * BEET + carrot_pound * CARROT;
	//�����ܰ���
	sum_pound = korea_pound + beet_pound + carrot_pound;
	//�����ۿ�
	if( sum_cost > BASE )
		rebate = sum_cost * REBATE;
	else
		rebate = 0;
	//�����������
	if( sum_pound >= WEIGHT1 )
		transport_cost = WCOST2 + sum_pound * WCOST3;
	else if( sum_pound > WEIGHT )
		transport_cost = WCOST1;
	else
		transport_cost = WCOST;
	
	//��ʾ��Ϣ
	printf( "The per pound fee is %10.5f$\n",sum_cost / sum_pound );
	printf( "The korea pound      %10.5f$\n",korea_pound );
	printf( "The Korea fee        %10.5f$\n",korea_pound * KOREA );
	printf( "The beet pound       %10.5f$\n",beet_pound );
	printf( "The beet fee         %10.5f$\n",beet_pound * BEET );
	printf( "The carrot pound     %10.5f$\n",carrot_pound );
	printf( "The carrot fee       %10.5f$\n",carrot_pound * CARROT );
	printf( "The sum pound        %10.5f$\n",sum_pound );
	printf( "The sum fee          %10.5f$\n",sum_cost );
	printf( "The rebate           %10.5f$\n",rebate );
	printf( "The transport fee    %10.5f$\n",transport_cost );
	printf( "The total cost       %10.5f$", (sum_cost + transport_cost) - rebate );
	
	return 0;
}
