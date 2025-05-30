/*
E2-Найти минимум

Ввести c клавиатуры массив из 5 элементов, 
найти минимальный из них.


Формат входных данных:
5 целых через пробел


Формат результата:
Одно единственное целое число
*/



#include <stdio.h>

#define SIZE 5

void Input (int array[], int n)
{
	for (int i=0; i<n; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
			return;
		}
	}
}

int Min_array(int array[], int n)
{
	int min= array[0];
	
	for(int i = 0; i< n; i++){
		if(min > array[i]){
			min=array[i];
		}
	}
	return min;
}


int main(int argc, char **argv)
{
	int array [SIZE] = {0};
	Input (&array[0], SIZE);
	
	printf("%d", Min_array(&array[0], SIZE));
	
	
	return 0;
}

