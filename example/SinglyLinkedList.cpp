/* list.c -- ֧���б�����ĺ��� */
#include "ProH.h"
#include <stdio.h>
#include <stdlib.h>
/* �ֲ�����ԭ��		          */
static void CopyToNode(Item item, Node * pnode);

/* �ӿں���                    */
/* ���б�����Ϊ���б�(���ڴ�й©��Σ��)       */
void InitializeList(Head * plist)
{
	*plist = NULL;
}

/* �������Ϊ���򷵻���         */
bool ListIsEmpty(const Head * plist)
{
	return *plist == NULL ? true : false;
}

/* ����б������򷵻���         */
bool ListIsFull(const Head * plist)
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
unsigned int ListItemCount(const Head * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;	/* ���õ��б�Ŀ�ʼ�� */

	while (pnode != NULL){
		count++;
		pnode = pnode->next;	/* ��pnode ����Ϊ��һ���ڵ� */
	}

	return count;
}

/* ���������Ŀ�Ľڵ�,��������ӵ� */
/* ��plist ָ����б�(������ʵ�ַ���)β�� */
bool AddItem(Item item, Head * plist)
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;		/* ʧ��ʱ�˳����� */

	CopyToNode(item, pnew);
	pnew->next = NULL;

	if (scan == NULL){		/*  ���б�,��˰�pnew */
		*plist = pnew;
	}						/*  �����б�ͷ��      */
	else{
		while (scan->next != NULL){
			scan = scan->next;
		}
		scan->next = pnew;
	}
	return true;
}

/* ����ÿ���ڵ㲢�����Ƿֱ�ִ����pfunָ��ĺ��� */
void Traverse(const Head * plist, void(* pfun)(Item item))
{
	Node * pnode = *plist;		/* ���õ��б�Ŀ�ʼ�� */
	while (pnode != NULL){
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/* �ͷ��� malloc() ������ڴ� */
/* ���б�ָ������ΪNULL       */
void EmptyTheList(Head * plist)
{
	Node * psave;
	
	while (*plist != NULL){
		psave = (*plist)->next;		/* ������һ���ڵ�ĵ�ַ */
		free(*plist);				/* �ͷŵ�ǰ�ڵ�         */
		*plist = psave;				/* ǰ������һ���ڵ�     */
	}
}

/* �ֲ���������   */
/* ��һ����Ŀ���Ƶ�һ���ڵ��� */
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
