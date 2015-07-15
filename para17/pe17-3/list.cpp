/* list.c -- 支持列表操作的函数 */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/* 局部函数原型		          */
static void CopyToArr(Item * ti, const Item * si);

/* 接口函数                    */
/* 把列表设置为空列表           */
void InitializeList(List * plist)
{
	plist->items = 0;
}

/* 如果链表为空则返回真         */
bool ListIsEmpty(const List * plist)
{
	return 0 == plist->items;
}

/* 如果列表已满则返回真         */
bool ListIsFull(const List * plist)
{
	return MAXSIZE == plist->items;
}

/* 返回节点数目                 */
int ListItemCount(const List * plist)
{
	return plist->items;
}

/* 创建存放项目的节点,并把它添加到 */
/* 由plist 指向的列表(较慢的实现方法)尾部 */
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

/* 访问每个节点并对它们分别执行由pfun指向的函数 */
void Traverse(const List * plist, void(*pfun)(Item item))
{
	for (size_t i = 0; i < plist->items; i++)
	{
		(*pfun)(plist->entries[i]);
	}
}

/* 释放由 malloc() 分配的内存 */
/* 把列表指针设置为NULL       */
void EmptyTheList(List * plist)
{
	plist->items = 0;
}

/* 局部函数定义   */
/* 把一个项目复制到数组中 */
static void CopyToArr(Item * ti, const Item * si)
{
	*ti = *si;
}
