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
	
	fputs( "�����Ҫʹ�õ��ļ�(Enter���˳�!):\n", stdout);
	while(fgets(filename, LIM, stdin) && *filename != '\n')
	{
		match = strchr(filename, '\n');
		if(match)
			*match = '\0';
		if((fp = fopen(filename, "r")) == NULL){
			fprintf(stderr, "�ļ�����[%s]����ȷ!\n", filename);
		}else{
			fputs( "�����ҪѰ�ҵ�λ��(������ĸq�˳���ǰʹ�õ��ļ�):\n", stdout);
			while(scanf("%lu", &site) == 1){
				while(getchar() != '\n')
					continue;
				while((ch = getc(fp)) != EOF && index++ < site)
						continue;
				if(ch != EOF)
				{
					fputs("�Ӹ�λ�õ��ַ�������:\n", stdout);
					putc(ch, stdout);
					while((ch = getc(fp)) != EOF && ch != '\n')
						putc(ch, stdout);
					putchar('\n');
				}else{
					fputs("�����λ�ó����ļ���Χ,�����¼���λ��.\n", stdout);
				}
				rewind(fp);
				index = 1;
				fputs("��������һ��ҪѰ�ҵ�λ��(������ĸq�˳���ǰʹ�õ��ļ�):\n", stdout);
			}
			if(fclose(fp) != 0){
				fprintf(stderr, "�޷��˳��ļ�[%s].\n", filename);
			}
			while(getchar() != '\n')
				continue;
		}
		fputs("�������һ��Ҫʹ�õ��ļ�(Enter���˳�!):\n", stdout);
	}
	
	free(filename);
	printf("Bye~\n");
	exit(EXIT_SUCCESS);
}
