/*
E6-Среднее арифметическое 2

Считать массив из 12 элементов и 
посчитать среднее арифметическое 
элементов массива.


Формат входных данных:
12 целых чисел через пробел


Формат результата:
Среднее арифметическое в формате "%.2f"
*/



#include <stdio.h>
#define SIZE 12

void Input(int array[], int n)
{
	for(int i=0;i<n;i++){
	if(scanf("%d", &array[i])!=1){
		printf("Wrong input");
	}
	}
	return;
}

double arithmetic_mean(int array[], int n)
{
	int sum=0;
	for(int i = 0;i<n; i++){
		sum+=array[i];
	}
	
	return (double)sum/n;
}


int main(int argc, char **argv)
{
	int array [SIZE] = {0};
	Input(&array[0], SIZE);
	printf("%.2f", arithmetic_mean(&array[0], SIZE));
	
	return 0;
}

