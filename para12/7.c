#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 2

int roll_n_dice(int dice, int sides);
int rollem(int sides);
void get_two_int(int * ptr);

int main(int argc, char ** argv)
{
	int * pair = (int *)malloc(SIZE * sizeof(int));
	int sets;
	int index;
	
	srand((unsigned int)time(0));
	printf("Enter the number of sets;enter q to stop.\n");
	
	while(scanf("%d", &sets) == 1){
	
		printf("How many sides and how many dice?\n");
		get_two_int(pair);
		printf("Here are %d sets of %d %d-sided throws.\n\t", sets, *pair, *(pair + 1));
		for(index = 0; index < sets; index++){
			printf("%d ", roll_n_dice(*(pair + 1), *pair));
			if((index + 1) % 15 == 0 && index != (sets - 1))
				printf("\n\t");
		}
			putchar('\n');
	
		printf("How many sets? Enter q to stop.\n");
	}
	
	exit(EXIT_SUCCESS);
}

int roll_n_dice(int dice, int sides)
{
	int subtotal = 0;
	int index;
	
	if(dice < 1){
		fprintf(stderr, "Need at least 1 dice.\n");
		exit(EXIT_FAILURE);
	}
	if(sides < 2){
		fprintf(stderr, "Need at least 2 sides.\n");
		exit(EXIT_FAILURE);
	}
	
	for(index = 0; index < dice; index++){
		subtotal += rollem(sides);
	}
	
	return subtotal;
}

int rollem(int sides)
{
	int roll;
	
	roll = rand() % sides + 1;
	return roll;
}

void get_two_int(int * ptr)
{
	char ch;
	
	while(scanf("%d %d", ptr, ptr + 1) != SIZE){
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a couple integer.\nPlease input an ");
		printf(" couple integer values, such as (25, 45), (78,578), (-23,0):");
	}
	
	while(getchar() != '\n')
		continue;
		
}
