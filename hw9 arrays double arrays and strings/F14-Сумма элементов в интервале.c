/*
F14-Сумма элементов

Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
Прототип функции int sum_between_ab(int from, int to, int size, int a[])


Формат входных данных:
Функция принимает концы отрезка from и to, размер массива, массив целых чисел
Input
4 6 1 2 3 4 5 6 7 8 9 10

Формат результата:
Функция возвращает сумму элементов в интервале [from, to]
Output
15

Решение:
дан массив чисел и два числа — границы отрезка: from и to.

Нужно пройтись по всем элементам массива и для каждого проверить, 
лежит ли он между from и to включительно (т. е. не меньше from и не больше to).

Если условие выполняется, нужно сложить найденные элементы 

В примере:
Массив: 1 2 3 4 5 6 7 8 9 10
Отрезок: [4, 6]
просматриваешь числа одно за другим и видишь, что подходят только: 4, 5, 6 — это три элемента, складываем

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

 int sum_between_ab(int from, int to, int size, int a[])
{
	if(from>to){
	int temp = from;
	from = to;
	to = temp;
	}
	
	
	
	int count = 0;
	
	for(int i=0; i<size; i++){
		if(a[i]>=from && a[i]<=to){ //проверяем 4<=a[i]<=6
		count+=a[i];
		}
	}
	
	return count;
}

int main(int argc, char **argv)
{
	int array[SIZE];
	Input(&array[0], SIZE);
	
	//Отрезок: [6, 4]
	int from = 6;
	int to = 4;
	
	int count = sum_between_ab(from, to, SIZE, array);
	           
	printf("%d", count);
	
	return 0;
}
