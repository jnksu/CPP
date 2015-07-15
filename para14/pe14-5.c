/* pe14-5.c 统计学生的分数 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMELEN 31
#define CSIZE 4
#define COURSE 3 

struct name{
	char fname[NAMELEN];
	char lname[NAMELEN];
};

typedef struct {
	struct name user;
	float  grade[COURSE];
	float averaged;
} STUDENT;

void clave(STUDENT * sp, int size);
void shin(STUDENT * sp, int size);
void shav(STUDENT * sp, int size);
float get_float(void);
void eatline(void);
void  reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	STUDENT carr[CSIZE];
	int count = 0;
	int index;
	
	printf("Please enter the first name.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	
	while(count < CSIZE && 
		fgets(carr[count].user.fname, NAMELEN, stdin) &&
			carr[count].user.fname[0] != '\n')
	{
		reject_ch(carr[count].user.fname, '\n');
		
		printf("Now enter the last name.\n");
		fgets(carr[count].user.lname, NAMELEN, stdin);
		reject_ch(carr[count].user.lname, '\n');
			
		for(index = 0; index < COURSE; index++){
			printf("Enter the grade: ");
			carr[count].grade[index] = get_float();
		}
		
		count++;
		
		if(count < CSIZE)
			printf("Enter the next.\n");
	}
	
	if(count > 0){
		clave(carr, count);
		shin(carr, count);
		shav(carr, count);
	}else{
		printf("No student?Too bad.\n");
	}
	exit(EXIT_SUCCESS);	
}
//计算每个成员的平均分
void clave(STUDENT * sp, int size)
{
	int index;
	int in;
	float subtot;
	
	for(index = 0; index < size; index++){
		for(in = 0, subtot = 0; in < COURSE; in++){
			subtot += sp[index].grade[in];
		}
		sp[index].averaged = subtot / COURSE;
	}
}
//显示学生信息 
void shin(STUDENT * sp, int size)
{
	int index;
	int in;
	char wholename[2 * NAMELEN];
	
	printf("Here is the list of student information: \n");
	for(index = 0; index < size; index++){
		strcpy(wholename, sp[index].user.fname);
		strcat(wholename, " ");
		strcat(wholename, sp[index].user.lname);
		printf("%27s: ", wholename);
		for(in = 0; in < COURSE; in++)
			printf("%6.1f ", sp[index].grade[in]);
		printf("Average: %5.1f\n", sp[index].averaged);
	}
	
}
//计算并显示平均成绩
void shav(STUDENT * sp, int size)
{
	int in,index;
	float tot = 0;
	float * cou = (float *)calloc( COURSE, sizeof(float) );
	
		for(index = 0; index < size; index++){
			for(in = 0; in < COURSE; in++)
				cou[in] += sp[index].grade[in];
		}
		
		for(index = 0; index < COURSE; index++){
			tot += cou[index];
			printf("class%4d: %5.1f \n", index, cou[index] / size);
		}
		
		printf("ave: %5.1f \n", tot / (COURSE * size));
		
	free(cou);	
}
//读取成绩
float get_float(void)
{
	float va;
	int ch;
	
	while(scanf("%f", &va) != 1 || va < 0 || va > 100){
		if(va < 0 || va > 100){
			printf("please enter fit number.\n");
			eatline();
		}
		else{
			while((ch = getchar()) != '\n')
				putchar(ch);
			printf(" is not number,\nplease enter the ");
			printf("number value, such as 25.0, 23.4 or 78.0: ");
		}	
	}
	
	eatline();
	return va;
}

void eatline(void)
{
	while(getchar() != '\n')
		continue;
}

void  reject_ch(char * str, int ch)
{
	char * match;
	
	match = strchr(str, ch);
	
	if(match)
		*match = '\0';
}
