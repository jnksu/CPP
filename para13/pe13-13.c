/* ��ȡͼƬ���ݲ���ʾͼƬ�ʹ洢ͼƬ(�����������) -- pe13-13.c */
#include <stdio.h>
#include <stdlib.h>
#define LEVELS 10
#define COLS 31
#define ROWS 20
static void remove_pul(int (*pic)[COLS - 1]);

int main(int argc, char ** argv)
{
	const char * match_str = " .':~*=&%@";	//�ַ�ƥ�䴮
	char (* pic)[COLS] = (char (*)[COLS])calloc(ROWS * COLS, sizeof(char));	//�ӹ��������
	int  (* pic_num)[COLS - 1] = (int (*)[COLS - 1])calloc(ROWS * (COLS - 1), sizeof(int)); //�����������
	FILE * in, * out;	//��������ļ�
	int index, indexNest;//��������
	int match_exc = 0;   //�ַ�ƫ��
	
	//�ж������в����Ƿ�Ϸ�
	if(argc == 3){
		//�򿪳�ʼ�����ļ�
		if((in = fopen(*(argv + 2), "r")) == NULL){
			fprintf(stderr, "can not open file %s.\n", *(argv + 2));
			exit(EXIT_FAILURE);
		}
		//������ļ�
		if((out = fopen(*(argv + 1), "a")) == NULL){
			fprintf(stderr, "Can not open file %s.\n", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		//�ӳ�ʼ�����ļ���ȡͼ����Ϣ
		for(index = 0; index < ROWS; index++)
			for(indexNest = 0; indexNest < COLS - 1; indexNest++){
				fscanf(in, "%d", &match_exc);
				*(*(pic_num + index) + indexNest) = match_exc; 
		}
		
		//�����������
		remove_pul(pic_num);
		
		//�������������ת��Ϊ�ַ�ͼ����Ϣ
		for(index = 0; index < ROWS; index++)
			for(indexNest = 0; indexNest < COLS - 1; indexNest++){
				*(*(pic + index) + indexNest) = *(match_str + *(*(pic_num + index) + indexNest));
		}
		
		//�رճ�ʼ�����ļ�
		if(fclose(in) != 0){
			fprintf(stderr, "Error in closing %s", *(argv + 2));
			exit(EXIT_FAILURE);
		}
		
		//������ַ�ͼ����������������ļ�,����ʾ
		for(index = 0; index < ROWS; index++){
			fprintf(stdout, "%s\n", *(pic + index));
			fprintf(out, "%s\n", *(pic + index));
		}
		
		//�ر�����ļ�
		if(fclose(out) != 0){
			fprintf(stderr, "Error in closing %s", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		
	}else{
		fprintf(stderr,"Usage: %s [targetFileName] [SourceFileName].\n", *argv );
		exit(EXIT_FAILURE);
	}
	
	//�ͷ���Ӧ�ڴ�
	free(pic);
	free(pic_num);
	printf("Bye~!\n");
	exit(EXIT_SUCCESS);
}


static void remove_pul(int (* pic)[COLS - 1])
{
	int row,col;
	
	/*�������ֵ*/
	//���Ͻ�
	if((**pic - *(*pic + 1)) > 1 && (**pic - **(pic + 1)) > 1)
		**pic = (*(*pic + 1) + **(pic + 1)) / 2;
	//���½�
	if(*(*(pic + ROWS - 1) +COLS - 2) - *(*(pic + ROWS - 1) + COLS - 3) > 1 && *(*(pic + ROWS - 1) + COLS - 2) - *(*(pic + ROWS - 2) + COLS - 2) > 1)
		*(*(pic + ROWS - 1) +COLS - 2) = (*(*(pic + ROWS - 1) + COLS - 3) + *(*(pic + ROWS - 2) + COLS - 2)) / 2;
	//���½�
	if(**(pic + ROWS - 1) - *(*(pic + ROWS - 1) + 1) > 1 && **(pic + ROWS - 1) - **(pic + ROWS - 2) > 1)
		**(pic + ROWS - 1) = (*(*(pic + ROWS - 1) + 1) + **(pic + ROWS - 2)) / 2;
	//���Ͻ�
	if(*(*pic + COLS - 2) - *(*pic + COLS - 3) > 1 && *(*pic + COLS - 2) - *(*(pic + 1) + COLS - 2) > 1)
		*(*pic + COLS - 2) = (*(*pic + COLS - 3) + *(*(pic + 1) + COLS - 2)) / 2;
		
	/*����߽�ֵ*/
	//�ϱ�
	for(col = 1; col < COLS - 2; col++){
		int num   = *(*pic + col);
		int letf  = *(*pic + col - 1);
		int right = *(*pic + col + 1);
		int down  = *(*(pic + 1) + col);
		
		if(num - letf > 1 && num - right > 1 && num - down > 1)
			*(*pic + col) = (letf + right + down) / 3;
	}
	//�±�
	for(col = 1; col < COLS - 2; col++){
		int num   = *(*(pic + ROWS - 1) + col);
		int letf  = *(*(pic + ROWS - 1) + col - 1);
		int right = *(*(pic + ROWS - 1) + col + 1);
		int up    = *(*(pic + ROWS - 2) + col);
		
		if(num - letf > 1 && num - right > 1 && num - up > 1)
			*(*(pic + ROWS - 1) + col) = (letf + right + up) / 3;
	}
	//���
	for(row = 1; row < ROWS - 1; row++){
		int up    = **(pic + row - 1);
		int down  = **(pic + row + 1);
		int right = *(*(pic + row) + 1);
		int num   = **(pic + row); 
		
		if(num - up > 1 && num - down > 1 && num - right > 1)
			**(pic + row) = (up + down + right) / 3;
	}
	//�ұ�
	for(row = 1; row < ROWS - 1; row++){
		int up   = *(*(pic + row - 1) + COLS - 2);
		int down = *(*(pic + row + 1) + COLS - 2);
		int left = *(*(pic + row) + COLS - 3); 
		int num  = *(*(pic + row) + COLS - 2);
		
		if(num - up > 1 && num - down > 1 && num - left > 1)
			*(*(pic + row) + COLS - 2) = (left + up + down) / 3;
	}
	
	/*��������ֵ*/
	for(row = 1; row < ROWS - 1; row++)
		for(col = 1; col < COLS - 2; col++){
			int up    = *(*(pic + row - 1) + col);
			int down  = *(*(pic + row + 1) + col);
			int left  = *(*(pic + row) + col - 1);
			int right = *(*(pic + row) + col + 1);
			int num   = *(*(pic + row) + col);
			
			if( num - left > 1 && num - right > 1 && num - up > 1 && num - down > 1)
				*(*(pic + row) + col) = (left + right + up + down) / 4;
		}	
}
