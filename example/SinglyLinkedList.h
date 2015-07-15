/* list.h -- ���б����͵�ͷ�ļ� */
#ifndef LIST_H
#define LIST_H 
#include <stdbool.h>

/* �ض��ڳ�������� */
#define TSIZE 45	 // ���Ƭ���������С  		
struct film
{
	char title[TSIZE];
	int rating;
};

/* һ�����Ͷ��� */
typedef struct film Item;

struct node
{
	Item item;
	struct node * next;
};

typedef struct node Node;

/* ͷָ��(����һ������) */
typedef Node * Head;

/* ����ԭ��									*/
/* ����: ��ʼ��һ���б�                     */
/* ����ǰ: plist ָ��һ���б�               */
/* ������: ���б���ʼ��Ϊ���б�           */
void InitializeList(Head * plist);

/* ����: ȷ���б��Ƿ�Ϊ���б�               */
/* ����ǰ: plist ָ��һ���ѳ�ʼ�����б�      */
/* ������: ������б�Ϊ���򷵻�true; ���򷵻�false  */
bool ListIsEmpty(const Head * plist);

/* ����: ȷ���б��Ƿ�����                   */
/* ����ǰ: plist ָ��һ���ѳ�ʼ�����б�     */
/* ������: ������б������򷵻�true; ���򷵻�false  */
bool ListIsFull(const Head  * plist);

/* ����: ȷ���б�����Ŀ�ĸ���               */
/* ����ǰ: plist ָ��һ���ѳ�ʼ�����б�     */
/* ������: ���ظ��б�����Ŀ�ĸ���           */
unsigned int ListItemCount(const Head  * plist);

/* ����: ���б�β���һ����Ŀ               */
/* ����ǰ: item ��Ҫ�����ӵ��б����Ŀ      */
/*         plist ָ��һ���ѳ�ʼ�����б�     */
/* ������: ������ܵĻ�,���б��β�����һ������Ŀ  */
/*         ��������true, ���򷵻�false      */
bool AddItem(Item item, Head  * plist);

/* ����: ��һ�������������б��е�ÿ����Ŀ   */
/* ����ǰ: plist ָ��һ���Ѿ���ʼ�����б�   */
/*         pfunָ��һ������,�ú�������һ��  */
/*         Item���������޷���ֵ             */
/* ������: pfunָ��ĺ��������õ�           */
/*         �б��е�ÿ����Ŀһ��             */
void Traverse(const Head  * plist, void(*pfun)(Item item));

/* ����: �ͷ��ѷ�����ڴ�                   */
/* ����ǰ: plist ָ��һ���ѳ�ʼ�����б�     */
/* ������: Ϊ���б������ڴ��Ѿ��ͷ�       */
/*         ���Ҹ��б���Ϊ���б�          */
void EmptyTheList(Head  * plist);
#endif
