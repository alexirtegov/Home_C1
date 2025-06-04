/*
F5-Максимум в массиве

Написать только одну функцию, 
которая находит максимальный элемент в массиве. 
Всю программу загружать не надо.
Прототип функции: int find_max_array(int size, int a[])


Формат входных данных:
Массив состоящий из целых чисел. 
Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.


Input
773 307 371 548 531 765 402 27 573 591 217 859 662 493 173 174 125 591 324 231 130 394 573 65 570 258 343 3 586 14 785 296 140 726 598 262 807 794 510 465 66 895 182 218 302 34 205 252 687 660 952 737 2 32 310 680 36 139 346 139 489 217 767 544 158 774 883 154 802 136 569 377 867 423 224 176 118 660 513 734 45 978 983 749 909 601 270 147 433 737 789 304 842 769 815 503 190 399 3

Формат результата:
Одно целое число

Output
983
Решение:
*/

#include <stdio.h>

int Input_SIZE (void)
{
	int SIZE;
	if(scanf("%d", &SIZE)!=1){
		printf("Error");
		return 0;
	}
	return SIZE;
}


void Input(int array[], int n) // вписываем значения в ячейки памяти массива по порядку
{
	for(int i = 0; i<n; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
			return;
		}
	}
}

int find_max_array (int size, int a[]) // находим максимум в значениях массива
{
	int max = a[0];
	
	for(int i = 0; i<size; i++){
		if(max < a[i]){
			max = a [i];
		}
	}
	return max;
}


void print_ALL(int max)
{
	printf("%d",max);
	return;
}

int main(int argc, char **argv)
{
	int SIZE = Input_SIZE ();
	
	int array [SIZE];
	Input(array, SIZE);
	
	find_max_array(SIZE, array);
	
	print_ALL(find_max_array(SIZE, array));
	
	return 0;
}
