/* list.c -- ֧���б�����ĺ��� */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/* �ֲ�����ԭ��		          */
static void CopyToNode(Item item, Node * pnode);

/* �ӿں���                    */
/* ���б�����Ϊ���б�           */
void InitializeList(List * plist)
{
	plist->head = NULL;
	plist->end = NULL;
}

/* �������Ϊ���򷵻���         */
bool ListIsEmpty(const List * plist)
{
	return plist->end == NULL;
}

/* ����б������򷵻���         */
bool ListIsFull(const List * plist)
{
	Node * pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));

	if (pt == NULL)
		full = true;
	else{
		full = false;
		free(pt);
	}

	return full;
}

/* ���ؽڵ���Ŀ                 */
unsigned int ListItemCount(const List * plist)
{
	if (ListIsEmpty(plist))
	{
		return 0;
	}
	else
	{
		unsigned int count = 1;
		Node * pnode = plist->head;
		while (pnode != plist->end)
		{
			++count;
			pnode = pnode->next;
		}
		return count;
	}
}

/* ���������Ŀ�Ľڵ�,��������ӵ� */
/* ��plist ָ����б�(������ʵ�ַ���)β�� */
bool AddItem(Item item, List * plist)
{
	Node * pnew;
	Node * scan = plist->head;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;		/* ʧ��ʱ�˳����� */

	CopyToNode(item, pnew);
	pnew->next = NULL;

	if (scan == NULL){		/*  ���б�,��˰�pnew */
		plist->head = pnew;
		plist->end = pnew;
	}						/*  �����б�ͷ��      */
	else{
		plist->end->next = pnew;
		plist->end = pnew;
	}
	return true;
}

/* ����ÿ���ڵ㲢�����Ƿֱ�ִ����pfunָ��ĺ��� */
void Traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pnode = plist->head;		/* ���õ��б�Ŀ�ʼ�� */

	while (pnode != plist->end){
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
	//��β���
	(*pfun)(pnode->item);
}

/* �ͷ��� malloc() ������ڴ� */
/* ���б�ָ������ΪNULL       */
void EmptyTheList(List * plist)
{
	Node * psave;

	while (plist->head != plist->end)
	{
		psave = plist->head->next;		//���浱ǰ������һ�����
		free(plist->head);				//�ͷŵ�ǰ���
		plist->head = psave;			//ָ����һ�����
	}
	
	free(plist->end);					//�ͷ�β���
}

/* �ֲ���������   */
/* ��һ����Ŀ���Ƶ�һ���ڵ��� */
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
