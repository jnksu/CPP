//names_st.c -- 定义names_st函数
#include <stdio.h>
#include <stdlib.h>
#include "names.h"	// 包含头文件

//函数定义
void get_names(names * pn)
{
	int index;

	printf("Please enter your first name: ");
	fgets(pn->first, SLEN, stdin);

	index = 0;
	while (pn->first[index] != '\n' && pn->first[index] != '\0'){
		index++;
	}

	if (pn->first[index] == '\n')
		pn->first[index] = '\0';
	else{
		while (getchar() != '\n')
			continue;
	}

	printf("Please enter your last names: ");
	fgets(pn->last, SLEN, stdin);
	
	index = 0;
	while (pn->last[index] != '\n' && pn->last[index] != '\0')
		index++;
	if (pn->first[index] == '\n')
		pn->first[index] = '\0';
	else{
		while (getchar() != '\n')
			continue;
	}
}

void show_names(const names * pn)
{
	printf("%s %s", pn->first, pn->last);
}


int main(int argc, char ** argv)
{
	names candidate;
	
	get_names(&candidate);
	printf("Let's welcome ");
	show_names(&candidate);
	printf("to this program!\n");
	
	return EXIT_SUCCESS;
}
