/*
F2-Четные в начало

Написать только одну функцию, которая ставит в начало массива 
все четные элементы, а в конец – все нечетные. 
Не нарушайте порядок следования чисел между собой. 
Строго согласно прототипу:.
void sort_even_odd(int n, int a[])




Формат входных данных:
Функцийя принимает на вход целые числа

Input
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

Формат результата:
Отсортированный исходный массив

Output
20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1

Решение: создаем второй массив, сначала копируем в него четную часть, 
затем сохраняя его индекс копируем нечетную, копируем его обратно
*/


void sort_even_odd(int n, int a[])
{
	int temp_array[n];
	int index =0;
	
	for(int i =0; i<n; i++){
		if(a[i]%2==0){
			temp_array[index]=a[i];
			index++;
		}
	}
	
	for(int i =0; i<n; i++){
		if(a[i]%2!=0){
			temp_array[index]=a[i];
			index++;
		}
	}
	
	for(int i =0; i<n; i++){
		a[i]=temp_array[i];
	}
}


#include <stdio.h>
#define SIZE 20



int main(int argc, char **argv)
{
	int array[SIZE];
	
	//ввод первоначальных значений массива
	for(int i=0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
	
	sort_even_odd(SIZE, array);
	
	//вывод
	for(int i=0; i<SIZE; i++){
		printf("%d ", array[i]);
	}
	
	return 0;
}

