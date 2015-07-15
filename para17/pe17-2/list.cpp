/* list.c -- 支持列表操作的函数 */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/* 局部函数原型		          */
static void CopyToNode(Item item, Node * pnode);

/* 接口函数                    */
/* 把列表设置为空列表           */
void InitializeList(List * plist)
{
	plist->head = NULL;
	plist->end = NULL;
}

/* 如果链表为空则返回真         */
bool ListIsEmpty(const List * plist)
{
	return plist->end == NULL;
}

/* 如果列表已满则返回真         */
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

/* 返回节点数目                 */
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

/* 创建存放项目的节点,并把它添加到 */
/* 由plist 指向的列表(较慢的实现方法)尾部 */
bool AddItem(Item item, List * plist)
{
	Node * pnew;
	Node * scan = plist->head;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;		/* 失败时退出函数 */

	CopyToNode(item, pnew);
	pnew->next = NULL;

	if (scan == NULL){		/*  空列表,因此把pnew */
		plist->head = pnew;
		plist->end = pnew;
	}						/*  放在列表头部      */
	else{
		plist->end->next = pnew;
		plist->end = pnew;
	}
	return true;
}

/* 访问每个节点并对它们分别执行由pfun指向的函数 */
void Traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pnode = plist->head;		/* 设置到列表的开始处 */

	while (pnode != plist->end){
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
	//对尾结点
	(*pfun)(pnode->item);
}

/* 释放由 malloc() 分配的内存 */
/* 把列表指针设置为NULL       */
void EmptyTheList(List * plist)
{
	Node * psave;

	while (plist->head != plist->end)
	{
		psave = plist->head->next;		//保存当前结点的下一个结点
		free(plist->head);				//释放当前结点
		plist->head = psave;			//指向下一个结点
	}
	
	free(plist->end);					//释放尾结点
}

/* 局部函数定义   */
/* 把一个项目复制到一个节点中 */
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
