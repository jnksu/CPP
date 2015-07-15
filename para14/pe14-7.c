/* pe14-7.c -- 把结构内容保存到文件中 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40		//书名最大长度
#define MAXAUTL 40		//作者最大长度
#define MAXBKS  10		//图书最多本数
 
typedef struct {				//图书模版	
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
} BOOK;

void update(BOOK * bpt);
void  reject_ch(char * str, int ch);
char get_let(char * str);
void modtit(BOOK * tep);
void modaut(BOOK * tep);
void modval(BOOK * tep);
float get_plus(void);
void eat_line(void);

int main(int argc, char ** argv)
{
	BOOK library[MAXBKS];	//结构数组	
	int count = 0;		    //总的图书计数			
	int index, filecount;   //filecount为文件中图书条目
	FILE * pbooks;
	int size = sizeof(BOOK);
	
	//打开图书信息文件
	if((pbooks = fopen("book.dat", "r+b")) == NULL){
		fprintf(stderr, "Can't open book.dat\n");
		exit(EXIT_FAILURE);
	}
	rewind(pbooks);	//定位到文件开始处
	//读取显示文件中的信息
	while(count < MAXBKS && 
		fread(&library[count], size, 1, pbooks) == 1)
	{
		if(count == 0)
			fprintf(stdout, "Current contents of book.dat: \n");
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);
			
		//修改处	
		fputs("Do you wish to change or delete this entry?<y/n>", stdout);
		if(get_let("yn") == 'y'){
			printf("Enter c to change, d to delete entry: ");
			if(get_let("cd") == 'c'){
				update(&library[count]);
			}else{
				count--; //删除该条目
			}
		}
		
		count++;
	}
	fclose(pbooks);		//关闭读模式下的文件 
	filecount = count;	//暂存文件已有的记录
	//判断文件是否已经写满
	if(count == MAXBKS){
		fputs("The book.dat is full.", stdout);
		exit(EXIT_FAILURE);
	}
	//提示输入并记录到数组中
	fputs("Please add new book titles.\n", stdout);
	fputs("Press [enter] at the start of a line to stop.\n", stdout);
	while(count < MAXBKS && 
		fgets(library[count].title, MAXTITL, stdin) &&
			library[count].title[0] != '\n'){
				reject_ch(library[count].title, '\n');
				
				fputs("Now enter the author.\n", stdout);
				fgets(library[count].author, MAXAUTL, stdin);
				reject_ch(library[count].author, '\n');
				
				fputs("Now enter the value.\n", stdout);
				scanf("%f", &library[count].value);
				
				while(getchar() != '\n')
					continue;			//清空输入行
				count++;	
				if(count < MAXBKS)
					fputs("Enter the next title.\n", stdout);
	}
	//打开写模式下的文件 
	if((pbooks = fopen("book.dat", "wb")) == NULL){
		fprintf(stderr, "Can't open book.dat\n");
		exit(EXIT_FAILURE);
	}
	//输出所有的图书信息,并将用户输入的文件信息写入文件
	if(count > 0){
		fputs("Here is the list of your books: \n", stdout);
		for(index = 0; index < count; index++){
				printf("%s by %s: $%.2f\n", library[index].title, 
					library[index].author, library[index].value);
		}
		
		fwrite(&library[0], size, count, pbooks);
	}else{
		fputs("No Books? Too bad.\n", stdout);
	}
	
	fputs("Bye~!\n", stdout);
	fclose(pbooks);
	exit(EXIT_SUCCESS);
}

void update(BOOK * bpt)
{
	char ch;
	BOOK temp = *bpt;
	
	//Tips
	printf("Enter the letter that indicates your choice:\n");
	printf("t) modify title a) modify author\n");
	printf("v) modify value s) quit,saving changes\n");
	printf("q) quit, ignore changes\n");
	
	while((ch = get_let("tavsq")) != 's' && ch != 'q'){
		
		switch(ch){
			case 't':modtit(&temp);
					 break;
			case 'a':modaut(&temp);
					 break;
			case 'v':modval(&temp);
					 break;
		}
		
		printf("t) modify title a) modify author\n");
		printf("v) modify value s) quit,saving changes\n");
		printf("q) quit, ignore changes\n");
	}
	
	if(ch == 's'){
		*bpt = temp;
	}
	
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
//获取选项
char get_let(char * str)
{
	int ch;
	
	while(!strchr(str, (ch = getchar())))
		printf("Enter a character in the list %s", str);
	
	while(getchar() != '\n')
		continue;
	
	return ch;
}
//修改标题
void modtit(BOOK * tep)
{
	fputs("Enter new title: \n", stdout);
	fgets(tep->title, MAXTITL, stdin);
	reject_ch(tep->title, '\n');
	
	while(getchar() != '\n')
		continue;

}
 //修改作者
void modaut(BOOK * tep)
{
	fputs("Enter new author: \n", stdout);
	fgets(tep->author, MAXAUTL, stdin);
	reject_ch(tep->author, '\n');
	
	while(getchar() != '\n')
		continue;
}
//修改价格
void modval(BOOK * tep)
{
	fputs("Enter new value: \n", stdout);
	tep->value = get_plus();	
}
//获得正的浮点
float get_plus(void)
{
	float value;
	int ch;
	
	while((scanf("%f", &value)) != 1 || value < 0 ){
		if(value < 0){
			printf("please enter fit number.\n");
			eat_line();
		}else{
			while((ch = getchar()) != '\n')
				putchar(ch);
			printf(" is not number.\nplease enter the ");
			printf("number value, such as 25.0, 23.4 or 78.0: ");
		}
	}
	
	eat_line();
	
	return value;
}

void eat_line(void)
{
	while(getchar() != '\n')
		continue;
}
