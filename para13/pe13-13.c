/* 读取图片数据并显示图片和存储图片(消除尖峰脉冲) -- pe13-13.c */
#include <stdio.h>
#include <stdlib.h>
#define LEVELS 10
#define COLS 31
#define ROWS 20
static void remove_pul(int (*pic)[COLS - 1]);

int main(int argc, char ** argv)
{
	const char * match_str = " .':~*=&%@";	//字符匹配串
	char (* pic)[COLS] = (char (*)[COLS])calloc(ROWS * COLS, sizeof(char));	//加工后的数据
	int  (* pic_num)[COLS - 1] = (int (*)[COLS - 1])calloc(ROWS * (COLS - 1), sizeof(int)); //待处理的数据
	FILE * in, * out;	//输入输出文件
	int index, indexNest;//遍历索引
	int match_exc = 0;   //字符偏移
	
	//判断命令行参数是否合法
	if(argc == 3){
		//打开初始数据文件
		if((in = fopen(*(argv + 2), "r")) == NULL){
			fprintf(stderr, "can not open file %s.\n", *(argv + 2));
			exit(EXIT_FAILURE);
		}
		//打开输出文件
		if((out = fopen(*(argv + 1), "a")) == NULL){
			fprintf(stderr, "Can not open file %s.\n", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		//从初始数据文件读取图像信息
		for(index = 0; index < ROWS; index++)
			for(indexNest = 0; indexNest < COLS - 1; indexNest++){
				fscanf(in, "%d", &match_exc);
				*(*(pic_num + index) + indexNest) = match_exc; 
		}
		
		//消除尖峰脉冲
		remove_pul(pic_num);
		
		//将处理过的数据转换为字符图像信息
		for(index = 0; index < ROWS; index++)
			for(indexNest = 0; indexNest < COLS - 1; indexNest++){
				*(*(pic + index) + indexNest) = *(match_str + *(*(pic_num + index) + indexNest));
		}
		
		//关闭初始数据文件
		if(fclose(in) != 0){
			fprintf(stderr, "Error in closing %s", *(argv + 2));
			exit(EXIT_FAILURE);
		}
		
		//将存放字符图像的数组输出到结果文件,并显示
		for(index = 0; index < ROWS; index++){
			fprintf(stdout, "%s\n", *(pic + index));
			fprintf(out, "%s\n", *(pic + index));
		}
		
		//关闭输出文件
		if(fclose(out) != 0){
			fprintf(stderr, "Error in closing %s", *(argv + 1));
			exit(EXIT_FAILURE);
		}
		
	}else{
		fprintf(stderr,"Usage: %s [targetFileName] [SourceFileName].\n", *argv );
		exit(EXIT_FAILURE);
	}
	
	//释放相应内存
	free(pic);
	free(pic_num);
	printf("Bye~!\n");
	exit(EXIT_SUCCESS);
}


static void remove_pul(int (* pic)[COLS - 1])
{
	int row,col;
	
	/*处理角落值*/
	//左上角
	if((**pic - *(*pic + 1)) > 1 && (**pic - **(pic + 1)) > 1)
		**pic = (*(*pic + 1) + **(pic + 1)) / 2;
	//右下角
	if(*(*(pic + ROWS - 1) +COLS - 2) - *(*(pic + ROWS - 1) + COLS - 3) > 1 && *(*(pic + ROWS - 1) + COLS - 2) - *(*(pic + ROWS - 2) + COLS - 2) > 1)
		*(*(pic + ROWS - 1) +COLS - 2) = (*(*(pic + ROWS - 1) + COLS - 3) + *(*(pic + ROWS - 2) + COLS - 2)) / 2;
	//左下角
	if(**(pic + ROWS - 1) - *(*(pic + ROWS - 1) + 1) > 1 && **(pic + ROWS - 1) - **(pic + ROWS - 2) > 1)
		**(pic + ROWS - 1) = (*(*(pic + ROWS - 1) + 1) + **(pic + ROWS - 2)) / 2;
	//右上角
	if(*(*pic + COLS - 2) - *(*pic + COLS - 3) > 1 && *(*pic + COLS - 2) - *(*(pic + 1) + COLS - 2) > 1)
		*(*pic + COLS - 2) = (*(*pic + COLS - 3) + *(*(pic + 1) + COLS - 2)) / 2;
		
	/*处理边界值*/
	//上边
	for(col = 1; col < COLS - 2; col++){
		int num   = *(*pic + col);
		int letf  = *(*pic + col - 1);
		int right = *(*pic + col + 1);
		int down  = *(*(pic + 1) + col);
		
		if(num - letf > 1 && num - right > 1 && num - down > 1)
			*(*pic + col) = (letf + right + down) / 3;
	}
	//下边
	for(col = 1; col < COLS - 2; col++){
		int num   = *(*(pic + ROWS - 1) + col);
		int letf  = *(*(pic + ROWS - 1) + col - 1);
		int right = *(*(pic + ROWS - 1) + col + 1);
		int up    = *(*(pic + ROWS - 2) + col);
		
		if(num - letf > 1 && num - right > 1 && num - up > 1)
			*(*(pic + ROWS - 1) + col) = (letf + right + up) / 3;
	}
	//左边
	for(row = 1; row < ROWS - 1; row++){
		int up    = **(pic + row - 1);
		int down  = **(pic + row + 1);
		int right = *(*(pic + row) + 1);
		int num   = **(pic + row); 
		
		if(num - up > 1 && num - down > 1 && num - right > 1)
			**(pic + row) = (up + down + right) / 3;
	}
	//右边
	for(row = 1; row < ROWS - 1; row++){
		int up   = *(*(pic + row - 1) + COLS - 2);
		int down = *(*(pic + row + 1) + COLS - 2);
		int left = *(*(pic + row) + COLS - 3); 
		int num  = *(*(pic + row) + COLS - 2);
		
		if(num - up > 1 && num - down > 1 && num - left > 1)
			*(*(pic + row) + COLS - 2) = (left + up + down) / 3;
	}
	
	/*处理中心值*/
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
