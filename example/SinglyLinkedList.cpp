/* list.c -- 支持列表操作的函数 */
#include "ProH.h"
#include <stdio.h>
#include <stdlib.h>
/* 局部函数原型		          */
static void CopyToNode(Item item, Node * pnode);

/* 接口函数                    */
/* 把列表设置为空列表(有内存泄漏的危险)       */
void InitializeList(Head * plist)
{
	*plist = NULL;
}

/* 如果链表为空则返回真         */
bool ListIsEmpty(const Head * plist)
{
	return *plist == NULL ? true : false;
}

/* 如果列表已满则返回真         */
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

/* 返回节点数目                 */
unsigned int ListItemCount(const Head * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;	/* 设置到列表的开始处 */

	while (pnode != NULL){
		count++;
		pnode = pnode->next;	/* 把pnode 设置为下一个节点 */
	}

	return count;
}

/* 创建存放项目的节点,并把它添加到 */
/* 由plist 指向的列表(较慢的实现方法)尾部 */
bool AddItem(Item item, Head * plist)
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;		/* 失败时退出函数 */

	CopyToNode(item, pnew);
	pnew->next = NULL;

	if (scan == NULL){		/*  空列表,因此把pnew */
		*plist = pnew;
	}						/*  放在列表头部      */
	else{
		while (scan->next != NULL){
			scan = scan->next;
		}
		scan->next = pnew;
	}
	return true;
}

/* 访问每个节点并对它们分别执行由pfun指向的函数 */
void Traverse(const Head * plist, void(* pfun)(Item item))
{
	Node * pnode = *plist;		/* 设置到列表的开始处 */
	while (pnode != NULL){
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/* 释放由 malloc() 分配的内存 */
/* 把列表指针设置为NULL       */
void EmptyTheList(Head * plist)
{
	Node * psave;
	
	while (*plist != NULL){
		psave = (*plist)->next;		/* 保存下一个节点的地址 */
		free(*plist);				/* 释放当前节点         */
		*plist = psave;				/* 前进到下一个节点     */
	}
}

/* 局部函数定义   */
/* 把一个项目复制到一个节点中 */
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
