/* pe14-2.c -- 计算天数 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define YEAR 12
#define STRLEN 4

//表示用户输入的日期
typedef struct {
	int years;
	int months;
	char abbrev[STRLEN];
	int days;
} year;
//系统预定义的时间
struct month{
	char name[10];
	char abbrev[STRLEN];
	int days;
	int monumb;
};

struct month months[YEAR] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}		
};

bool get_years(year * ptr);
void get_months(year * ptr);
int get_days(year * ptr);

int get_int(void);
void eat_line(void);
void  reject_ch(char * str, int ch);
bool isleap_year(year * ptr);
bool ismatch_mon(year * ptr);

int main(int argc, char ** argv)
{
	year input;

	fputs("Enter the year('q' for quit):", stdout);
	while(get_years(&input)){
		fputs("Enter the months like \"Jan\": ", stdout);
		get_months(&input);
		if(isleap_year(&input))
			months[1].days = 29;
		printf("%d-%02d-%02d has %d days.\n", input.years, 
			input.months, input.days, get_days(&input));
		fputs("Next year: ('q' for quit)", stdout);
	}
	
	printf("Bye~!\n");
	exit(EXIT_SUCCESS);
}

//读取年份
bool get_years(year * ptr)		
{
	
	while(scanf("%d", &(ptr->years)) == 1){
		if(ptr->years > 9999 || ptr->years < 1900){
			printf("%d is not an valid value,\n", ptr->years);
			printf("please enter an year value, such as 1992, 2000, or 1998: ");
			eat_line();
		}
		else{
			eat_line();
			return true;
		}
	}
	
	return false;
}
//读取月份
void get_months(year * ptr)
{
	while(fgets(ptr->abbrev, STRLEN, stdin) && !ismatch_mon(ptr)){
		printf("%s is not an month.\nPlease enter", ptr->abbrev);
		printf(" an month value, such as Jan, Nov, Feb, or Oct.\n");
	}
}
//读取天数
int get_days(year * ptr)
{
	int day;
	int index;
	
	printf("Enter an days value: ");
	day = get_int();
	
	while(day < 1 || day > (months[ptr->months].days) ){
		printf("Please enter fit days: ");
		day = get_int();
	}
	
	ptr->days = day;
	
	for(index = 0; index < ptr->months; index++ )
		day += months[index].days;

	return day;
}
//读取整型
int get_int(void)
{
	int input;
	char ch;
	
	while(scanf("%d", &input) != 1){
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value, such as 25, 18, or 3: ");
	}
	
	return input;
}
//读取剩余行
void eat_line(void)
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
//判断用户输入是否为闰年
bool isleap_year(year * ptr)
{
	int year = ptr->years;
	
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
//将月份缩写转换为实际的天数
bool ismatch_mon(year * ptr)
{
	int index;
	reject_ch(ptr->abbrev, '\n');
	
	*(ptr->abbrev) = toupper(*(ptr->abbrev));
	for(index = 1; *(ptr->abbrev + index) != '\0'; index++)
			*(ptr->abbrev + index) = tolower(*(ptr->abbrev + index));
			
	for(index = 0; index < YEAR; index++)
	{
		if(strcmp(months[index].abbrev, ptr->abbrev)== 0){
			ptr->months = index;
			return true;
		}
	}
	
	return false;
}
