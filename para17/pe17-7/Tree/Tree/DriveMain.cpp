//除去vs中的警告
#define _CRT_SECURE_NO_DEPRECATE
//测试修改的二叉树
#include "debug.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//最大单词数
#define MAXSTRLEN 81

//局部函数原型
static void pfun(Item item);
static char menu(void);
static void showInformation(Tree * ptree);
static void findWord(Tree * ptree);
static bool InitializeTreeFromFile(Tree * ptree, const char * pfile);
static void  reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	char ch;						//用户选项
	char fileName[MAXSTRLEN];		//文件名
	Tree wordTree;					//用于索引单词的二叉树
	
	//初始化二叉树
	InitializeTree(&wordTree);

	//输入文件名
	fputs("Enter name of file to be processed: \n", stdout);
	fgets(fileName, MAXSTRLEN, stdin);
	reject_ch(fileName, '\n');

	//初始化树
	InitializeTreeFromFile(&wordTree, fileName);

	//主菜单
	while ((ch = menu()) != 'q')
	{
		switch (ch)
		{
		case 's':showInformation(&wordTree);
			 break;
		case 'f':findWord(&wordTree);
			 break;
		default: fprintf(stderr, "Oh! The program get into trouble!\n");
			exit(EXIT_FAILURE);
		}
	}

	//销毁树
	DeleteAll(&wordTree);
	_CrtDumpMemoryLeaks();
	fputs("Bye~\n", stdout);
	return EXIT_SUCCESS;
}

//局部函数
static void pfun(Item item)
{
	printf("%s %d\n", item.word, item.count);
}

static char menu(void)
{
	int choice;

	fputs("Word counting program\n", stdout);
	fputs("Enter the letter corresponding to your choice:\n", stdout);
	fputs("s) show word list     f) find a word\n", stdout);
	fputs("q) quit\n:", stdout);

	while ((choice = getchar()) != EOF)
	{
		while (getchar() != '\n')
		{
			continue;
		}
		if (strchr("sfq", choice))
		{
			break;
		}
		else
		{
			fputs("Please enter an s, f, or q: ", stdout);
		}
	}

	return choice;
}

static void showInformation(Tree * ptree)
{
	fputs("Here is the word information.\n", stdout);
	Traverse(ptree, pfun);
}

static void findWord(Tree * ptree)
{
	char seekWord[MAXSTRLEN];
	Item temp;
	const Item * res;

	fputs("Please enter the word your want to seek:\n", stdout);
	fgets(seekWord, MAXSTRLEN, stdin);
	reject_ch(seekWord, '\n');

	strcpy(temp.word, seekWord);
	res = seekInTree(ptree, &temp);

	if (NULL == res)
	{
		fprintf(stdout, "Can't find this word in tree");
	}
	else
	{
		printf("%s %d\n", res->word, res->count);
	}
}

static bool InitializeTreeFromFile(Tree * ptree, const char * pfile)
{
	FILE * in;		//将要读取的文件流
	Item it;		//临时数据结构
	char word[MAXSTRLEN];

	if (NULL == (in = fopen(pfile, "r")))
	{
		fprintf(stderr, "Can't open %s\n", pfile);
		return false;
	}
	else
	{
		//将来程序要进行改进的话,要在此处进行改进
		while (1 == fscanf(in, "%s", word))
		{
			strcpy(it.word, word);
			AddItem(&it, ptree);				//添加项目到二叉树中
		}
	}

	//收尾工作
	if (fclose(in) != 0)
		fprintf(stderr, "Error in closing files\n");
	return true;
} 

static void  reject_ch(char * str, int ch)
{
	char * match;

	match = strchr(str, ch);

	if (match)
		*match = '\0';
}
