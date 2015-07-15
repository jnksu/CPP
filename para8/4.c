#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	char prev = '\n';
	unsigned int count_words = 0;
	unsigned int count_letter = 0;
	
	while((ch = getchar()) != EOF)
	{
		/*�ж�ch�Ƿ�Ϊ�հ��ַ�*/
		if(!ispunct(ch) && !isspace(ch))
		{	
			if(isspace(prev) || ispunct(prev))		//�ж�prev�Ƿ�Ϊ�հ��ַ�
				count_words++;
			count_letter++;
		}
		prev = ch;
	}
	
	printf("The words is %u,letter is %u,average letter %4.2f\n",count_words,count_letter,(float)count_letter / count_words);
	return 0;
}
