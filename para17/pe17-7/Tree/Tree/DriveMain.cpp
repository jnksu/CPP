//��ȥvs�еľ���
#define _CRT_SECURE_NO_DEPRECATE
//�����޸ĵĶ�����
#include "debug.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��󵥴���
#define MAXSTRLEN 81

//�ֲ�����ԭ��
static void pfun(Item item);
static char menu(void);
static void showInformation(Tree * ptree);
static void findWord(Tree * ptree);
static bool InitializeTreeFromFile(Tree * ptree, const char * pfile);
static void  reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	char ch;						//�û�ѡ��
	char fileName[MAXSTRLEN];		//�ļ���
	Tree wordTree;					//�����������ʵĶ�����
	
	//��ʼ��������
	InitializeTree(&wordTree);

	//�����ļ���
	fputs("Enter name of file to be processed: \n", stdout);
	fgets(fileName, MAXSTRLEN, stdin);
	reject_ch(fileName, '\n');

	//��ʼ����
	InitializeTreeFromFile(&wordTree, fileName);

	//���˵�
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

	//������
	DeleteAll(&wordTree);
	_CrtDumpMemoryLeaks();
	fputs("Bye~\n", stdout);
	return EXIT_SUCCESS;
}

//�ֲ�����
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
	FILE * in;		//��Ҫ��ȡ���ļ���
	Item it;		//��ʱ���ݽṹ
	char word[MAXSTRLEN];

	if (NULL == (in = fopen(pfile, "r")))
	{
		fprintf(stderr, "Can't open %s\n", pfile);
		return false;
	}
	else
	{
		//��������Ҫ���иĽ��Ļ�,Ҫ�ڴ˴����иĽ�
		while (1 == fscanf(in, "%s", word))
		{
			strcpy(it.word, word);
			AddItem(&it, ptree);				//������Ŀ����������
		}
	}

	//��β����
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