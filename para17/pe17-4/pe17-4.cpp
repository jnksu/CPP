/* mall.c -- ʹ��Queue�ӿ� */
/* ��queue.cһ�����       */
#include "ldbg.h"			//debug
#include <stdio.h>
#include <stdlib.h>			/* Ϊrand()��srand()�ṩԭ�� */
#include <time.h>			/* Ϊtime()�����ṩԭ��      */
#include "LoopQueue.h"		/* �ı�Item��typedef         */	
#define MIN_PER_HR 60.0

bool new_customer(double);				/* ���¹˿͵�����? */
Data customer_time(long when);			/* ���ù˿Ͳ���    */

int main(int argc, char ** argv)
{
	LoopQueue * line, * line1;			/* ģ�����						*/
	Data temp;							/* �����¹˿͵�����   		  	*/
	int hours;							/* ģ���Сʱ��       		  	*/
	int per_hour;						/* ÿСʱ�˿͵�ƽ����  		  	*/
	long cycle, cycle_limit;			/* ѭ��������, ���������Ͻ�   	*/
	long turn_aways = 0;				/* ��������������ܾ��Ĺ˿��� 	*/
	long customer = 0;					/* ��������еĹ˿���		  	*/
	long customer1 = 0;
	long served = 0;					/* ��ģ���ڼ�õ�����Ĺ˿��� 	*/
	long served1 = 0;
	long sum_line = 0;					/* �ۼƵĶ��г���			    */
	long sum_line1 = 0;
	int wait_time = 0;					/* �ӵ�ǰ��Sigmund���������ʱ��*/
	int wait_time1 = 0;
	double min_per_cust;				/* �˿͵�����ƽ�����ʱ��		*/
	long line_wait = 0;					/* �����ۼƵȴ�ʱ��				*/
	long line_wait1 = 0;

	line = createLoopQueue(10);
	line1 = createLoopQueue(10);
	srand(time(0));						/* �����ʼ��rand()����         */
	//����ģ���Сʱ��
	fputs("Case Study: Sigmund Lander's Advice Booth\n", stdout);
	fputs("Enter the number of simulation hours:\n", stdout);
	scanf_s("%d", &hours);
	cycle_limit = MIN_PER_HR * hours;
	//ÿ�˿͵���ʱ��
	fputs("Enter the average number of customers per hour: \n", stdout);
	scanf_s("%d", &per_hour);
	min_per_cust = MIN_PER_HR / per_hour;
	//�Զ��н��д���
	for (cycle = 0; cycle < cycle_limit; cycle++)
	{
		//�����1�������й˿͵���
		if (new_customer(min_per_cust))
		{
			if (LoopQueueIsFull(line) && LoopQueueIsFull(line1)){
				turn_aways++;					//�˿ͱ��ܾ�
			}
			else{
				temp = customer_time(cycle);
				if (countLoopQueue(line) < countLoopQueue(line1))
				{
					EnLoopQueue(line, temp);		//�˿����
					customer++;
				}
				//���ڶ������е��˽��ٵ�ʱ��
				else 
				{
					EnLoopQueue(line1, temp);
					customer1++;
				}
			}
		}
		//�����ʱ�����޵ȴ�
		if (wait_time <= 0 && !LoopQueueIsEmpty(line))
		{
			Data * de = DeLoopQueue(line);
			wait_time = de->process_time;
			line_wait += cycle - de->arrive;
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		//�������1��ʱ�޵ȴ�
		if (wait_time1 <= 0 && !LoopQueueIsEmpty(line1))
		{
			Data * de = DeLoopQueue(line1);
			wait_time1 = de->process_time;
			line_wait1 = cycle - de->arrive;
			served1++;
		}
		if (wait_time1 > 0)
		{
			wait_time1--;
		}

		sum_line += countLoopQueue(line);
		sum_line1 += countLoopQueue(line1);
	}

	if (customer > 0){
		printf("customers accepted: %ld\n", customer + customer1);
		printf("  customers served: %ld\n", served + served1);
		printf("         turnaways: %ld\n", turn_aways );
		printf("average queue size: %.2f\n",
			(double)(sum_line + sum_line1) / cycle_limit);
		printf(" average wait time: %.2f minutes\n",
			(double)(line_wait + line_wait1)/ ( served + served1));
	}
	else{
		fputs("No customers\n", stdout);
	}

	destroyLoopQueue(line);
	destroyLoopQueue(line1);
	fputs("Bye!\n", stdout);
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}

/* ���֮�������ͽ����ϵ�ȥ����! */
bool new_customer(double para)
{
	//�����ɵĹ˿͵���ʱ��С��һ����ʱ,������Ϊ�¹˿Ͳ���
	if (rand() * para / RAND_MAX < 1)
		return true;
	else
		return false;
}

/* when �ǹ˿͵�����ʱ��                                 			*/
/* �������ص�һ��Item�ṹ,�ýṹ�Ĺ˿͵���ʱ������Ϊwhen 			*/
/* ��Ҫ��ѯ��ʱ������Ϊһ����Χ��1��3֮������ֵ                   */
Data customer_time(long when)
{
	Data cust;

	cust.process_time = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
