/* pe13-10.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIM 81

int main(int argc, char ** argv)
{
	FILE * fp;
	unsigned long int site = 0;
	unsigned long int index = 1;
	char * filename = (char *)malloc(LIM * sizeof(char));
	int ch;
	char * match;
	
	fputs( "请键入要使用的文件(Enter键退出!):\n", stdout);
	while(fgets(filename, LIM, stdin) && *filename != '\n')
	{
		match = strchr(filename, '\n');
		if(match)
			*match = '\0';
		if((fp = fopen(filename, "r")) == NULL){
			fprintf(stderr, "文件名字[%s]不正确!\n", filename);
		}else{
			fputs( "请键入要寻找的位置(键入字母q退出当前使用的文件):\n", stdout);
			while(scanf("%lu", &site) == 1){
				while(getchar() != '\n')
					continue;
				while((ch = getc(fp)) != EOF && index++ < site)
						continue;
				if(ch != EOF)
				{
					fputs("从该位置的字符起如下:\n", stdout);
					putc(ch, stdout);
					while((ch = getc(fp)) != EOF && ch != '\n')
						putc(ch, stdout);
					putchar('\n');
				}else{
					fputs("键入的位置超出文件范围,请重新键入位置.\n", stdout);
				}
				rewind(fp);
				index = 1;
				fputs("请输入下一个要寻找的位置(键入字母q退出当前使用的文件):\n", stdout);
			}
			if(fclose(fp) != 0){
				fprintf(stderr, "无法退出文件[%s].\n", filename);
			}
			while(getchar() != '\n')
				continue;
		}
		fputs("请键入下一个要使用的文件(Enter键退出!):\n", stdout);
	}
	
	free(filename);
	printf("Bye~\n");
	exit(EXIT_SUCCESS);
}
