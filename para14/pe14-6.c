/* ���ļ��ж�ȡ��Ա��Ϣ���㲢��ʾ -- pe14-6.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAMELEN 31		//��Ҫ����������
#define PALNUM 19		//��Ա����
#define BUFFER_SIZE 80 //��Ҫ��������
		
struct name{
	char fname[NAMELEN];	//��
	char lname[NAMELEN];	//��
};

typedef struct {
	struct name names;	//��Ա����
	int oftb;			//�ϳ�����
	int hits;			//������
	int walks;			//������
	int RBIS;			//�ܵ���
	float batave;		//����ƽ���ɹ���
}PLAYERS;

void shin(PLAYERS * ptr, int size);

int main(int argc, char ** argv)
{
	PLAYERS * pl = (PLAYERS *)calloc(PALNUM, sizeof(PLAYERS));		//��Ա��Ϣ����
	PLAYERS temp;			//������ʱ��Ŵ��ļ���ȡ����Ա��Ϣ
	int playnum;			//��Ա���
	char * buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	const char * pld = "pld.dat";	//��Ա��Ϣ�ļ�����
	FILE * plf;						//��Ա��Ϣ�ļ�ָ��
	int index;
	
	if((plf = fopen(pld, "r")) == NULL){
		fprintf(stderr, "Could not open file %s input.\n", pld);
		exit(EXIT_FAILURE);
	}
	//����Ա��Ϣ���ļ���ȡ���ṹ������
	while(fgets(buffer, BUFFER_SIZE, plf)){
		//��������ʽ�Ϸ���
		if(sscanf(buffer, "%d %s %s %d %d %d %d", 
			&playnum, temp.names.fname, temp.names.lname, 
				&temp.oftb, &temp.hits, &temp.walks, &temp.RBIS) != 7){
					fprintf(stderr, "Bad input skipped: %s",
						buffer);
					continue;
		}
		//�����Ա����Ƿ�Ϸ�
		if(playnum > (PALNUM - 1) || playnum < 0){
			fprintf(stderr, "format of player number invalid!.\n");
			continue;
		}
		//����Ӧ����Ա��ֵ
		if(strcmp(temp.names.fname, pl[playnum].names.fname) != 0){
			strcpy(pl[playnum].names.fname, temp.names.fname);
			strcpy(pl[playnum].names.lname, temp.names.lname);
		}
		
		pl[playnum].oftb  += temp.oftb;
		pl[playnum].hits  += temp.hits;
		pl[playnum].walks += temp.walks;
		pl[playnum].RBIS  += temp.RBIS;
		
	}
	//�ر�ʹ�õ��ļ�
	if(fclose(plf) != 0){
		fprintf(stderr, "Error in closing file.\n");
		exit(EXIT_FAILURE);
	}
	
	//��ʱtemp���ڴ洢�ۼƺ� 
	temp.oftb = 0;
	temp.hits = 0;
	temp.walks = 0;
	temp.RBIS = 0;
	//�������ɹ��ʲ������ۼƺ�
	for(index = 0; index < PALNUM; index++){
		pl[index].batave = pl[index].hits / (float)(pl[index].oftb);
		temp.oftb  += pl[index].oftb;
		temp.hits  += pl[index].hits;
		temp.walks += pl[index].walks;
		temp.RBIS  += pl[index].RBIS;
	}
	//��ʾ��Ա��Ϣ���ۺ����
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
		//������Աȫ��
		strcpy(fullname, (ptr + index)->names.fname);
		strcat(fullname, " ");
		strcat(fullname, (ptr + index)->names.lname);
		//��ʾ��Ϣ
		printf("%13d %31s %14d %4d %5d %4d %15.1f\n",
			index, fullname, 
				(ptr + index)->oftb, (ptr + index)->hits, (ptr + index)->walks,
					(ptr + index)->RBIS, (ptr + index)->batave);
	}
}
