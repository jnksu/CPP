/*pe14-8.c -- 机票预定*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAMELEN 31	//姓名最大长度
#define PLVOLUM 12	//机舱座位最大数
#define ALPHA 27	//字母表
#define BUFFER 80 	//缓冲区

const  char * readFile = "ticket.dat";	//存储文件
const  char * writeFile = "ticket.dat";  //写入文件

struct name
{
	char fname[NAMELEN];
	char lname[NAMELEN];
};

typedef struct
{
	int seatid;
	bool assigned;
	struct name names;
} TICKET;

const char alphabetical[ALPHA] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getInt(void);
void eatLine(void);
int matchAlpha(int);
void showMenu(void);
char getLet(const char *);
bool deleteSeat(TICKET * );
bool isIdVaild(int , int );
bool registerUser(TICKET * );
bool IsRegister(TICKET *, int);
int EmptySeats(TICKET *, int );
int readInformation(TICKET * , int );
int writeInformation(TICKET *, int );
void initializationId(TICKET *, int );
void showListOfEmptySeats(TICKET *, int );
void showAlphabeticalListOfSeats(TICKET *, int );

int main(int argc, char ** argv)
{
	int choice;

	TICKET * inm = (TICKET *)calloc(PLVOLUM, sizeof(TICKET));
	//初始化
	readInformation(inm, PLVOLUM);
	//显示主菜单
	showMenu();
	//读取用户输入
	while((choice = getLet("abcdef")) != 'f'){
		switch(choice){
			case 'a':printf("The number of empty seats: %d\n", EmptySeats(inm, PLVOLUM));
					break;
			case 'b':showListOfEmptySeats(inm, PLVOLUM);
					break;
			case 'c':showAlphabeticalListOfSeats(inm, PLVOLUM);
					break;
			case 'd':if(!registerUser(inm)){	//判断座位是否已满
						fprintf(stderr, "%s\n", "The seats full!");	
					}
					break;
			case 'e':deleteSeat(inm);
					break;
		}
		showMenu();	
	}
	//将用户修改重新写入文件
	writeInformation(inm, PLVOLUM);
	free(inm);
	printf("%s\n", "Bye~!");
	exit(EXIT_SUCCESS);
}
//获得正确的座位号
int getInt(void)
{
	int val;
	char * buffer = (char *)malloc(BUFFER * sizeof(char));
	int read = 0;
	fgets(buffer, BUFFER, stdin);
	//如果用户非法输入
	while((read = sscanf(buffer, "%d", &val)) != 1 || !isIdVaild(val, PLVOLUM))
	{
		if(read == 1)
			fprintf(stderr, "%s\n", "The seatid invalid");
		else
			fprintf(stderr, "%s:%s\n", "Bad input skipped", buffer);

		fprintf(stdout, "%s\n", "Please try again");
		
		fgets(buffer, BUFFER, stdin);
	}

	free(buffer);
	return val;	
}
//将座位号转换为字母
int matchAlpha(int seatid)
{
	extern const char alphabetical[];
	return *(alphabetical + seatid);
}
//提示界面
void showMenu(void)
{
	fputs("To choose a function, entert its letter label:\n", stdout);
	fputs("a) Show number of empty seats\n", stdout);
	fputs("b) show list of empty seats\n", stdout);
	fputs("c) show alphabetical list of seats\n", stdout);
	fputs("d) Assign a customer to a seat assigment\n", stdout);
	fputs("e) Delete a seat assigment\n", stdout);
	fputs("f) Quit\n", stdout);
}
//获取正确的选项
char getLet(const char * str)
{
	char ch;
	ch = getchar();
	ch = tolower(ch);
	while(!strchr(str, ch)){
		eatLine();
		printf("Enter a character in the list %s\n", str);
		ch = getchar();
	}
	eatLine();

	return ch;
}
//取消座位号
bool deleteSeat(TICKET * rub)
{
	int id;
	printf("please enter seatsid\n");
	id = getInt();
	if(IsRegister(rub, id)){
		(rub + id)->assigned = false;
		return true;
	}
	else
		return false;
}
//刷新行缓冲
void eatLine(void)
{
	while(getchar() != '\n')
			continue;
}
//检查id合法性
bool isIdVaild(int match, int range)
{
	return (match >= 0 && match < range);
}
//注册用户
bool registerUser(TICKET * store)
{
	char  * buffer = (char *)malloc(BUFFER * sizeof(char));
	int val;

	if(EmptySeats(store, PLVOLUM) == 0)
		return false;
	else{
		//输入座位ID
		fprintf(stdout, "%s\n", "please enter seatid" );
		val = getInt();
		while(IsRegister(store, val)){
			fprintf(stdout, "%s\n", "The seats was invalid,Please try other again");
			val = getInt();
		}
		//输入姓名
		fprintf(stdout, "%s\n", "please enter your Names");
		fgets(buffer, BUFFER, stdin);

		while(sscanf(buffer, "%s %s", 
				(store + val)->names.fname, 
				(store + val)->names.lname) != 2){
			fprintf(stderr, "Bad input skipped: %s", buffer);
			fprintf(stdout, "%s\n", "Please try again");
			fgets(buffer, BUFFER, stdin);
		}
		//设置标志位
		(store + val)->assigned = true;
	}

	free(buffer);
	return true;
}
//判断该座位是否注册
bool IsRegister(TICKET * reg, int loc)
{
	if((reg + loc)->assigned)
		return true;
	else
		return false;
}
//读取信息
int readInformation(TICKET * box, int size)
{	
	extern const char * readFile;
	FILE * readIn;	
	int count;	//信息计数器
	TICKET temp;
	
	initializationId(box, PLVOLUM);
	//打开文件
	if((readIn = fopen(readFile, "rb")) == NULL){
		fprintf(stderr, "Can not open %s for input.\n", readFile);
		exit(EXIT_FAILURE);
	}
	//读取文件
	while(fread(&temp, sizeof(TICKET), 1, readIn) == 1){
		//检查ID的合法性
		if(!isIdVaild(temp.seatid, PLVOLUM)){
			fprintf(stderr, "bad id skipped: %d", temp.seatid);
			continue;			
		}else{
			*(box + temp.seatid) = temp;
			count++;		//记录读取个数
		}
	}
	//检查文件是否正常关闭
	if(fclose(readIn) != 0){
		fprintf(stderr, "Erro! can't closing File %s!\n", readFile);
		exit(EXIT_FAILURE);
	}

	return count;
}
//写入信息
int writeInformation(TICKET * source, int size)
{
	int count;	//信息计数器
	int index;
	FILE * writeOut;
	extern const char * writeFile;
	//打开文件
	if((writeOut = fopen(writeFile, "wb")) == NULL){
		fprintf(stderr, "Can not opne %s for write.\n", writeFile);
		exit(EXIT_FAILURE);
	}
	//检查参数合法性
	if(!isIdVaild(size, PLVOLUM + 1)){
		fprintf(stderr, "Array out of index bounds %d!.\n", size);
		exit(EXIT_FAILURE);
	}
	//写入文件
	for(index = 0; index < size; index++){
		if(fwrite((source + index), sizeof(TICKET), 1, writeOut) == 1)
			count++;
	}
	//检查文件是否正常关闭
	if(fclose(writeOut) != 0){
		fprintf(stderr, "Erro in closing File %s\n", writeFile);
		exit(EXIT_FAILURE);
	}

	return count;
}
//初始化座位id
void initializationId(TICKET * tic, int size)
{
	int index;
	for(index = 0; index < size; index++){
		(tic + index)->seatid = index;
	} 
}
//显示空位的数量
int EmptySeats(TICKET * statis, int size)
{
	int index;
	int count = 0;	//计数空位

	for(index = 0; index < size; index++){
		//判断是否占用	
		if( !((statis + index)->assigned) )
			count++;
	}

	return count;
}
//显示空位列表
void showListOfEmptySeats(TICKET * statis, int size)
{
	int index;
	fputs("The list of empty seats\n", stdout);
	//寻找空位
	for(index = 0; index < size; index++){
		if(!((statis + index)->assigned))
			printf("%4d", index);
	}

	putchar('\n');
}
//显示字母列表的空座位号
void showAlphabeticalListOfSeats(TICKET * statis, int size)
{
	int index;

	fputs("The list of empty seats\n", stdout);
	for(index = 0; index < size; index++){
		if(!((statis + index)->assigned))
			printf(" %c ", matchAlpha(index));
	}

	putchar('\n');
}
