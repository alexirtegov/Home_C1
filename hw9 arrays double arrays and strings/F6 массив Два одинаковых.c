/*
F6-Два одинаковых

Написать только одну логическую функцию, 
которая определяет, верно ли, что среди элементов массива
есть два одинаковых. Если ответ «да», 
функция возвращает 1; если ответ «нет», то 0. 
Строго согласно прототипу:
int is_two_same(int size, int a[]);


Формат входных данных:
Массив состоящий из целых чисел. 

Input
1 2 1 4 5


Формат результата:
Функция возвращает 1 или 0

Output
YES
Решение:
*/


#include <stdio.h>

int What_SIZE(void)
{
	int number;
	if(scanf("%d", &number)!=1 || number<=0){
		printf ("Wrong input\n");
		return 0;
	}
		return number;
}

void Input_array(int array[], int SIZE)
{
	for(int i =0; i<SIZE; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
			return;
		}
	}
}


int is_two_same(int size, int a[]) //получили размер SIZE и адрес первой ячейки памяти массива &array[0]
{ //пример 1 2 1 4 5
	for(int i=0; i<size-1; i++){
		for(int j=i+1; j<size; j++){
			if(a[i]==a[j]){
				return 1;
			}
		}
	}
	return 0;
}



int main(int argc, char **argv)
{
	int SIZE = What_SIZE();
	int array [SIZE];
	Input_array(array, SIZE);
	
	
	if (is_two_same(SIZE, array) == 1){
		printf("YES");
	}else{
		printf("NO");
	}
	
	return 0;
}

