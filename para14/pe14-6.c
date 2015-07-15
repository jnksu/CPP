/* 从文件中读取球员信息计算并显示 -- pe14-6.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAMELEN 31		//将要处理的最长名字
#define PALNUM 19		//球员数量
#define BUFFER_SIZE 80 //将要处理的最长行
		
struct name{
	char fname[NAMELEN];	//姓
	char lname[NAMELEN];	//名
};

typedef struct {
	struct name names;	//球员姓名
	int oftb;			//上场次数
	int hits;			//击中数
	int walks;			//走垒数
	int RBIS;			//跑点数
	float batave;		//击球平均成功率
}PLAYERS;

void shin(PLAYERS * ptr, int size);

int main(int argc, char ** argv)
{
	PLAYERS * pl = (PLAYERS *)calloc(PALNUM, sizeof(PLAYERS));		//球员信息数组
	PLAYERS temp;			//用于临时存放从文件读取的球员信息
	int playnum;			//球员编号
	char * buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	const char * pld = "pld.dat";	//球员信息文件名字
	FILE * plf;						//球员信息文件指针
	int index;
	
	if((plf = fopen(pld, "r")) == NULL){
		fprintf(stderr, "Could not open file %s input.\n", pld);
		exit(EXIT_FAILURE);
	}
	//将球员信息从文件读取到结构数组中
	while(fgets(buffer, BUFFER_SIZE, plf)){
		//检查输入格式合法性
		if(sscanf(buffer, "%d %s %s %d %d %d %d", 
			&playnum, temp.names.fname, temp.names.lname, 
				&temp.oftb, &temp.hits, &temp.walks, &temp.RBIS) != 7){
					fprintf(stderr, "Bad input skipped: %s",
						buffer);
					continue;
		}
		//检查球员编号是否合法
		if(playnum > (PALNUM - 1) || playnum < 0){
			fprintf(stderr, "format of player number invalid!.\n");
			continue;
		}
		//对相应的球员赋值
		if(strcmp(temp.names.fname, pl[playnum].names.fname) != 0){
			strcpy(pl[playnum].names.fname, temp.names.fname);
			strcpy(pl[playnum].names.lname, temp.names.lname);
		}
		
		pl[playnum].oftb  += temp.oftb;
		pl[playnum].hits  += temp.hits;
		pl[playnum].walks += temp.walks;
		pl[playnum].RBIS  += temp.RBIS;
		
	}
	//关闭使用的文件
	if(fclose(plf) != 0){
		fprintf(stderr, "Error in closing file.\n");
		exit(EXIT_FAILURE);
	}
	
	//此时temp用于存储累计和 
	temp.oftb = 0;
	temp.hits = 0;
	temp.walks = 0;
	temp.RBIS = 0;
	//计算击球成功率并计算累计和
	for(index = 0; index < PALNUM; index++){
		pl[index].batave = pl[index].hits / (float)(pl[index].oftb);
		temp.oftb  += pl[index].oftb;
		temp.hits  += pl[index].hits;
		temp.walks += pl[index].walks;
		temp.RBIS  += pl[index].RBIS;
	}
	//显示球员信息和综合情况
	shin(pl, PALNUM);
	
	printf("\nSummary\n");
	printf("Official times:%4d\n", temp.oftb);
	printf("Hits:%4d\n", temp.hits);
	printf("Walks:%4d\n", temp.walks);
	printf("RBIS:%4d\n", temp.RBIS);
	printf("Batting Average:%5.1f\n", temp.hits / (float)(temp.oftb));
	
	free(pl);
	free(buffer);
	exit(EXIT_SUCCESS);
}

void shin(PLAYERS * ptr, int size)
{
	int index;
	char fullname[NAMELEN];
	
	printf("\nPlay's number %31s Official times Hits Walks RBIS Batting average\n",
		"Name");
	for(index = 0; index < size; index++){
		//计算球员全名
		strcpy(fullname, (ptr + index)->names.fname);
		strcat(fullname, " ");
		strcat(fullname, (ptr + index)->names.lname);
		//显示信息
		printf("%13d %31s %14d %4d %5d %4d %15.1f\n",
			index, fullname, 
				(ptr + index)->oftb, (ptr + index)->hits, (ptr + index)->walks,
					(ptr + index)->RBIS, (ptr + index)->batave);
	}
}
