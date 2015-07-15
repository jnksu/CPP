/*从文件流或者标准输入流中读取Double数值并计算平均值*/
#include <stdio.h>
#include <stdlib.h>

double sum(FILE * fp, int * num);

int main(int argc, char ** argv)
{

	FILE * stream = stdin;
	int * num = (int *)malloc(sizeof(int));
	double temp;
	double sum_ = 0;
	*num = 0;
	
	if(argc <= 2){
		if(argc == 2){
			if((stream = fopen(*(argv + 1), "rb")) == NULL)
			{
				fprintf(stderr, "Could not open %s for input.\n", *(argv + 1));
				exit(EXIT_FAILURE);
			}
			sum_ = sum(stream, num);
			fclose(stream);
		}
		else{
			while(fscanf(stream, "%lf", &temp)){
				sum_ += temp;
				(*num)++;
			}
		}
	}else{
		fprintf(stderr, "Usage: %s [filename]\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	if(*num > 0){
		printf("Average of %d values = %f\n", *num, sum_ / (*num));
	}else{
		printf("No valid data.\n");
	}
	free(num);
	printf("Bye!\n");
	exit(EXIT_SUCCESS);
}

double sum(FILE * fp, int * num)
{
	size_t bytes;
	double sum = 0.0;
	double temp;
	
	while((bytes = fread(&temp, sizeof(double), 1, fp)) > 0){
		sum += temp;
		(*num)++;
	}
	
	return sum;
}
