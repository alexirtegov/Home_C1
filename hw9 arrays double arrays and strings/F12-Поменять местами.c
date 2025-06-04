/*
F12-Поменять местами

Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
Прототип функции void change_max_min(int size, int a[])


Формат входных данных:
Функция принимает на вход размер массива и массив чисел типа int
Input
1 2 3 4 5 6 7 8 9 10

Формат результата:
Функция не возвращает значения, измененный массив сохраняется на месте исходного.
Output
10 2 3 4 5 6 7 8 9 1

Решение:
*/

	#include <stdio.h>
	#define SIZE 10

void Input(int array[], int n) // вписываем значения в ячейки памяти массива по порядку
{
	for(int i = 0; i<n; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
			return;
		}
	}
}

void change_max_min(int size, int a[])
{
	// находим максимум и его позицию
	int max = a[0];
	int position_max=0;
	for(int i = 0; i<size; i++){
		if(max < a[i]){
			max = a[i];
			position_max=i;
		}
	}
	
	//находим минимум и его позицию
	int min = a[0];
	int position_min=0;
	for(int i = 0; i<size; i++){
		if(min > a[i]){
			min = a[i];
			position_min=i;
		}
	}
	
	//меняем местами
	int temp = a[position_max];
	a[position_max]=a[position_min];
	a[position_min] = temp;
	
	//выведим новый массив
	for(int i = 0; i<size; i++){
		printf("%d ", a[i]);
	}
	return;
}


int main(int argc, char **argv)
{
	int array [SIZE] = {0};
	Input(&array[0], SIZE);
	
	change_max_min(SIZE, array);

	return 0;
}
