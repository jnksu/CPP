/* list.c -- ֧���б�����ĺ��� */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/* �ֲ�����ԭ��		          */
static void CopyToArr(Item * ti, const Item * si);

/* �ӿں���                    */
/* ���б�����Ϊ���б�           */
void InitializeList(List * plist)
{
	plist->items = 0;
}

/* �������Ϊ���򷵻���         */
bool ListIsEmpty(const List * plist)
{
	return 0 == plist->items;
}

/* ����б������򷵻���         */
bool ListIsFull(const List * plist)
{
	return MAXSIZE == plist->items;
}

/* ���ؽڵ���Ŀ                 */
int ListItemCount(const List * plist)
{
	return plist->items;
}

/* ���������Ŀ�Ľڵ�,��������ӵ� */
/* ��plist ָ����б�(������ʵ�ַ���)β�� */
bool AddItem(Item * item, List * plist)
{
	if (ListIsFull(plist))
	{
		return false;
	}
	else
	{
		CopyToArr(plist->entries + plist->items, item);
		plist->items++;
		return true;
	}
}

/* ����ÿ���ڵ㲢�����Ƿֱ�ִ����pfunָ��ĺ��� */
void Traverse(const List * plist, void(*pfun)(Item item))
{
	for (size_t i = 0; i < plist->items; i++)
	{
		(*pfun)(plist->entries[i]);
	}
}

/* �ͷ��� malloc() ������ڴ� */
/* ���б�ָ������ΪNULL       */
void EmptyTheList(List * plist)
{
	plist->items = 0;
}

/* �ֲ���������   */
/* ��һ����Ŀ���Ƶ������� */
static void CopyToArr(Item * ti, const Item * si)
{
	*ti = *si;
}
