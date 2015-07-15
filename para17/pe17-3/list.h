/* list.h -- ���б����͵�ͷ�ļ� */
#ifndef LIST_H
#define LIST_H 
#include <stdbool.h>

/* �ض��ڳ�������� */
#define TSIZE 45	 // ���Ƭ���������С 
#define MAXSIZE 10

//�û��Զ�����������
typedef struct item 
{
	char title[TSIZE];
	int rating;
} Item;

//�����������
typedef struct node
{
	Item item;
	struct node * next;
} Node;

//��������������
typedef struct list
{
	Item entries[MAXSIZE];					//��Ŀ����
	int	 items;								//�б�����Ŀ�ĸ���
} List;

/* ����ԭ��								   */
/* ����: ��ʼ��һ���б�                     */
/* ����ǰ: plist ָ��һ���б�               */
/* ������: ���б���ʼ��Ϊ���б�            */
void InitializeList(List * plist);

/* ����: ȷ���б��Ƿ�Ϊ���б�               */
/* ����ǰ: plist ָ��һ���ѳ�ʼ�����б�      */
/* ������: ������б�Ϊ���򷵻�true; ���򷵻�false  */
bool ListIsEmpty(const List * plist);

/* ����: ȷ���б��Ƿ�����                   */
/* ����ǰ: plist ָ��һ���ѳ�ʼ�����б�     */
/* ������: ������б������򷵻�true; ���򷵻�false  */
bool ListIsFull(const List * plist);

/* ����: ȷ���б�����Ŀ�ĸ���               */
/* ����ǰ: plist ָ��һ���ѳ�ʼ�����б�     */
/* ������: ���ظ��б�����Ŀ�ĸ���           */
int ListItemCount(const List * plist);

/* ����: ���б�β���һ����Ŀ               */
/* ����ǰ: item ��Ҫ�����ӵ��б����Ŀ      */
/*         plist ָ��һ���ѳ�ʼ�����б�     */
/* ������: ������ܵĻ�,���б��β�����һ������Ŀ  */
/*         ��������true, ���򷵻�false      */
bool AddItem(Item * item, List * plist);

/* ����: ��һ�������������б��е�ÿ����Ŀ   */
/* ����ǰ: plist ָ��һ���Ѿ���ʼ�����б�   */
/*         pfunָ��һ������,�ú�������һ��  */
/*         Item���������޷���ֵ             */
/* ������: pfunָ��ĺ��������õ�           */
/*         �б��е�ÿ����Ŀһ��             */
void Traverse(const List * plist, void(*pfun)(Item item));

/* ����: �ͷ��ѷ�����ڴ�                   */
/* ����ǰ: plist ָ��һ���ѳ�ʼ�����б�     */
/* ������: Ϊ���б������ڴ��Ѿ��ͷ�       */
/*         ���Ҹ��б���Ϊ���б�           */
void EmptyTheList(List * plist);
#endif
