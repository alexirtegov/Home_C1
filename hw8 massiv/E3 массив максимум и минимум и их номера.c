/*
E3-Максимум и минимум и их номера

Считать массив из 10 элементов и 
найти в нем максимальный и 
минимальный элементы и их номера.



Формат входных данных:
10 целых чисел через пробел


Формат результата:
4 целых числа через пробел: 
номер максимума, максимум, номер минимума, минимум.
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

int Max_array(int array[], int n) // находим максимум в значениях массива
{
	int max = array[0];
	
	for(int i = 0; i<n; i++){
		if(max < array[i]){
			max = array [i];
		}
	}
	return max;
}

int Position_Max(int array[], int n) //находим позицию в массиве для максимума
{
	int max = array[0];
	int position=0;
	
	for(int i = 0; i<n; i++){
		if(max < array[i]){
			max = array [i];
			position=i;
		}
	}
	return position+1;
}


int Min_array(int array[], int n) //находим минимум
{
	int min = array[0];
	
	for(int i = 0; i<n; i++){
		if(min > array[i]){
			min = array [i];
		}
	}
	return min;
}

int Position_Min(int array[], int n) // позиция минимума
{
	int min = array[0];
	int position=0;
	
	for(int i = 0; i<n; i++){
		if(min > array[i]){
			min = array [i];
			position=i;
		}
	}
	return position+1;
}

void print_ALL(int pos_max, int max, int pos_min, int min)
{
	printf("%d %d %d %d", pos_max, max, pos_min, min);
	return;
}

int main(int argc, char **argv)
{
	int array [SIZE] = {0};
	Input(&array[0], SIZE);
	
	Max_array(&array[0], SIZE);
	Position_Max(&array[0], SIZE);
	
	Min_array(&array[0], SIZE);
	Position_Min(&array[0], SIZE);
	
	print_ALL(Position_Max(&array[0], SIZE), Max_array(&array[0], SIZE), Position_Min(&array[0], SIZE), Min_array(&array[0], SIZE));
	
	return 0;
}

