#define METRIC 0
#define US 1
#include <stdio.h>
void set_mode(int);
void get_info(void);
float get_float(void);
void show_info(void);

static int mode;
static float distance;
static float fule;

void set_mode(int arg)
{
	if(arg > US){
		mode = US;
		printf("Invalid mode specified %d(US)used\n", mode);
	}
	else
		mode = arg;
}

void get_info(void)
{
	printf("Enter distance traveled in %s:", mode == US ? "miles" : "kilometers");
		while((distance = get_float()) < 0)
				printf("Error!\n");
	printf("Enter fule consumed in %s:", mode == US ? "gallons" : "liters");
		while((fule = get_float()) <= 0)
				printf("Error!\n");
}

float get_float(void)
{
	float temp;
	char ch;
	
	while(scanf("%f", &temp) != 1){
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a float\n");
		printf("please input a number like 221.2 or 13:");
	}
	
	while(getchar() != '\n')
		continue;

	return temp;
}

void show_info(void)
{
	float ans;
	
	if(mode == US){
		ans = distance / fule;
		printf("Fule consumption is %4.1lf miles per gallon\n", ans);
	}
	else if(mode == METRIC){
		ans = (fule / distance) * 100.0;
		printf("Fule consumption is %4.1lf liters per 100 km\n", ans);
	}
	else
		printf("Program Error!\n");
}
