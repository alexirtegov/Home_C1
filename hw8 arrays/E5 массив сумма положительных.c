/*
E5-Сумма положительных элементов

Считать массив из 10 элементов и посчитать 
сумму положительных элементов массива.





Формат входных данных:
10 целых чисел через пробел


Формат результата:
Одно целое число - 
сумма положительных элементов массива
*/


#include <stdio.h>
#define SIZE 10

void Input (int array[], int n)
{
	for(int i = 0; i<n; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
			return;
		}
	}
}

int sum_positive_numbers(int array[], int n)
{
	int sum=0;
	for(int i = 0; i<n; i++){
		if(array[i]>0){
			sum +=array[i];
		}
	}
	return sum;
	
}



int main(int argc, char **argv)
{
	int array[SIZE] = {0};
	Input (&array[0], SIZE);
	
	printf("%d", sum_positive_numbers(&array[0], SIZE));
	
	return 0;
}
