/*
E10-Циклический сдвиг вправо на 4

Считать массив из 12 элементов и выполнить 
циклический сдвиг ВПРАВО на 4 элемента.


Формат входных данных:
12 целых чисел через пробел
1 2 3 4 5 6 7 8 9 10 11 12

Формат результата:
12 целых чисел через пробел
9 10 11 12 1 2 3 4 5 6 7 8

*/

#include <stdio.h>
#define SIZE 12


void Input (int array[], int n)
{
	for(int i = 0; i<n; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
		}
	}
}

void Shift_value(int array[], int n) 
{
	int last = array [n-1]; //храним 12
	int to_last = array [n-2];// 11
	int to_to_last = array [n-3]; //10
	int to_to_to_last = array [n-4];//9
	
	int k = 4;	
	for(int i = n-1; i>=k; i--){ 
		array[i]=array[i-k]; //11 присваивать 7
	}
	array [3] = last;
	array [2] = to_last;
	array [1] = to_to_last;
	array [0] = to_to_to_last;
}


void Print_arr(int array[], int n)
{
	for(int i =0;i<n;i++){
		printf("%d ", array[i]);
	}
}


int main(int argc, char **argv)
{
	int array[SIZE];
	Input(&array[0], SIZE);
	Shift_value(&array[0], SIZE);
	
	Print_arr(&array[0], SIZE);
	
	
	return 0;
}
