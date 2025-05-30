/*
E17-Только один раз

Дан массив из 10 элементов. 
В массиве найти элементы, которые 
в нем встречаются только один раз, и вывести их на экран.


Формат входных данных:
10 целых чисел через пробел
5   -4   0  1   4  -3  -3  3  0  2

Формат результата:
Элементы которые встречаются только один раз через пробел
5  -4  1  4  3  2

*/


#include <stdio.h>
#define SIZE 10

void Input(int array[], int n)
{
	for(int i =0; i<n; i++){
		if(scanf("%d", &array[i])!=1)
		printf("Error");
	}
}


int main(int argc, char **argv)
{
	int array[SIZE]={0};
	Input(&array[0], SIZE);
	
	

	
	for(int i=0; i<SIZE; i++){
	int count =0;
		
		for(int j=0; j<SIZE; j++){
			if(j!=i && array[i]==array[j]){ //Когда j = 0 и i = 0, условие j != i ложно мы пропускаем сравнение
				count++;
			}
			
		}
		if(count==0)
		printf("%d ", array[i]);
	
	}
		
		
	
	
	
	return 0;
}
