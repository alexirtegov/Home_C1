/*
E9-Циклический сдвиг вправо

Считать массив из 10 элементов 
и выполнить циклический сдвиг ВПРАВО на 1.

Формат входных данных:
10 целых чисел через пробел


Формат результата:
10 целых чисел через пробел сдвинутых вправо 
на 1 элемент циклически
*/

#include <stdio.h>
#define SIZE 10


void Input (int array[], int n)
{
	for(int i = 0; i<n; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
		}
	}
}

void Shift_value(int array[], int n) //1 2 3 4 5 6 7 8 9 10 должно стать 10 1 2 3 4 5 6 7 8 9
{
	int last = array [n-1]; //храним 10
		
	for(int i = n-1; i>0; i--){//i= 9 => 8 =>7 => 6 => 5 =>4 => 3 =>2 =>1 
		array[i]=array[i-1];//1 2 3 4 5 6 7 8 9 9=> 1 2 3 4 5 6 7 8 8 9=> 1 2 3 4 5 6 7 7 8 9 => 1 2 3 4 5 6 6 7 8 9=> 1 2 3 4 5 5 6 7 8 9 => 1 2 3 4 4 5 6 7 8 9 => 1 2 3 3 4 5 6 7 8 9=> 1 2 2 3 4 5 6 7 8 9 => 1 1 2 3 4 5 6 7 8 9
	}
	array [0] = last;
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

