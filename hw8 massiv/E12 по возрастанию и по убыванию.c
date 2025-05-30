/*
E12-По возрастанию и по убыванию

Считать массив из 10 элементов и отсортировать 
первую половину по возрастанию, а вторую – по убыванию.

Формат входных данных:
10 целых чисел через пробел
5 4 3 2 1 6 7 8 9 10

Формат результата:
Исходный массив. Первая часть отсортирована 
по возрастанию, вторая половина по убыванию.
1 2 3 4 5 10 9 8 7 6
*/

#include <stdio.h>
#define SIZE 10

void Input(int array[], int n)
{
	
	for(int i =0;i<n;i++){
	if(scanf("%d", &array[i])!=1){
		printf("Error");
		return;
	}
}
}

void Rep_val(int array[], int i, int j){
	int temp;
	temp = array [i];
	array [i]= array[j];
	array[j] = temp; 
}



void Replace_values_1 (int array[], int n) //5 4 3 2 1 N 6 7 8 9 10 Должно стать 1 2 3 4 5 
{
	int i, j, N=n/2;
	for(i=0; i<N; i++){
		for(j=i+1;j<N;j++){
			if(array[i]>array[j]){
				Rep_val(&array[0], i, j);
			}
		}
	}
}
	
	
	
void Replace_values_2 (int array[], int n) //5 4 3 2 1 N 6 7 8 9 10 Должно стать 10 9 8 7 6
{	
	int a, b, N=n/2;
	for(a=N; a<n; a++){ 
		for(b=a+1;b<n;b++){
			if(array[a]<array[b]){
				Rep_val(&array[0], a, b);
			}
		}
	}
	
	
	
	
}

void Print_arr(int array[], int n)
{
	for(int i =0;i<n;i++){
		printf("%d ", array[i]);
	}
}



int main(int argc, char **argv)
{
	int array[SIZE] ={0};
	
	Input(&array[0], SIZE);
	
	Replace_values_1 (&array[0], SIZE);
	Replace_values_2 (&array[0], SIZE);
	
	Print_arr(&array[0], SIZE);
	
	
	return 0;
}
