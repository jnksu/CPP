// friend.c -- 嵌套结构的例子
#include <stdio.h>
#include <stdlib.h>
#define LEN 20

const char * msgs[5] =
{
	" Thank you for the wonderful evening, ",
	"You certainly prove that a ",
	"is a special kind of guy. We must get together",
	"over a delicious ",
	" and have a few laughs"
};
struct names{				//第一个结构
	char first[LEN];
	char last[LEN];
};
struct guy{					//第二个结构
	struct names handle;	//嵌套结构
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(int argc, char ** argv)
{
	struct guy fellow = {	//初始化一个变量
		{"Ewen", "Villard"},
		"grilled salmon",
		"personality coach",
		58112.00
	};
	
	printf("Dear %s, \n\n", fellow.handle.first);
	printf("%s%s.\n", *msgs, fellow.handle.first);
	printf("%s%s\n", *(msgs + 1), fellow.job);
	printf("%s\n", *(msgs + 2));
	printf("%s%s%s", *(msgs + 3), fellow.favfood, *(msgs + 4));
	
	if(fellow.income > 150000.0)
		fputs("!!\n", stdout);
	else if(fellow.income > 75000.0)
		fputs("!\n", stdout);
	else
		fputs(".\n", stdout);
	printf("\n%40s%s\n", " ", "See you soon, ");
	printf("%40s%s\n", " ", "Shalala");
	
	exit(EXIT_SUCCESS);
}
