/* list.h -- 简单列表类型的头文件 */
#ifndef LIST_H
#define LIST_H 
#include <stdbool.h>

/* 特定于程序的声明 */
#define TSIZE 45	 // 存放片名的数组大小 
#define MAXSIZE 10

//用户自定义数据类型
typedef struct item 
{
	char title[TSIZE];
	int rating;
} Item;

//结点数据类型
typedef struct node
{
	Item item;
	struct node * next;
} Node;

//单链表数据类型
typedef struct list
{
	Item entries[MAXSIZE];					//项目数组
	int	 items;								//列表中项目的个数
} List;

/* 函数原型								   */
/* 操作: 初始化一个列表                     */
/* 操作前: plist 指向一个列表               */
/* 操作后: 该列表被初始化为空列表            */
void InitializeList(List * plist);

/* 操作: 确定列表是否为空列表               */
/* 操作前: plist 指向一个已初始化的列表      */
/* 操作后: 如果该列表为空则返回true; 否则返回false  */
bool ListIsEmpty(const List * plist);

/* 操作: 确定列表是否已满                   */
/* 操作前: plist 指向一个已初始化的列表     */
/* 操作后: 如果该列表已满则返回true; 否则返回false  */
bool ListIsFull(const List * plist);

/* 操作: 确定列表中项目的个数               */
/* 操作前: plist 指向一个已初始化的列表     */
/* 操作后: 返回该列表中项目的个数           */
int ListItemCount(const List * plist);

/* 操作: 在列表尾添加一个项目               */
/* 操作前: item 是要被增加到列表的项目      */
/*         plist 指向一个已初始化的列表     */
/* 操作后: 如果可能的话,在列表的尾部添加一个新项目  */
/*         函数返回true, 否则返回false      */
bool AddItem(Item * item, List * plist);

/* 操作: 把一个函数作用于列表中的每个项目   */
/* 操作前: plist 指向一个已经初始化的列表   */
/*         pfun指向一个函数,该函数接受一个  */
/*         Item参数并且无返回值             */
/* 操作后: pfun指向的函数被作用到           */
/*         列表中的每个项目一次             */
void Traverse(const List * plist, void(*pfun)(Item item));

/* 操作: 释放已分配的内存                   */
/* 操作前: plist 指向一个已初始化的列表     */
/* 操作后: 为该列表分配的内存已经释放       */
/*         并且该列表被置为空列表           */
void EmptyTheList(List * plist);
#endif
