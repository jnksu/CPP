// friend.c -- Ƕ�׽ṹ������
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
struct names{				//��һ���ṹ
	char first[LEN];
	char last[LEN];
};
struct guy{					//�ڶ����ṹ
	struct names handle;	//Ƕ�׽ṹ
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(int argc, char ** argv)
{
	struct guy fellow = {	//��ʼ��һ������
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
