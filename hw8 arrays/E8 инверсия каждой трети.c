/*
E8-Инверсия каждой трети

Считать массив из 12 элементов 
и выполнить инверсию для каждой 
трети массива.

Формат входных данных:
12 целых чисел через пробел


Формат результата:
12 целых чисел через пробел
*/




#include <stdio.h>
#define SIZE 12

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



void Replace_values_1 (int array[], int n)
{
	int i, j, N=n/3;//N=4
	for(i=0; i<N; i++){ // 1 2 3 4 N 5 6 7 8 N 9 10 11 12
		for(j=i+1;j<N;j++){
			if(i+j==N-1){
				Rep_val(&array[0], i, j);
			}
		}
	}
}
	

void Replace_values_2 (int array[], int n)
{	
	int i, j, N=n/3;//12/3   N=4
	for(i=N; i<N*2; i++){ //от 4 до 7
		for(j=i+1;j<N*2;j++){
			if(i+j==n-1){ //==11
				Rep_val(&array[0], i, j);
			}
		}
	}
}


void Replace_values_3 (int array[], int n)
{	
	int i, j, N=n*2/3;//12*2/3   N=8
	for(i=N; i<n; i++){ //от 8 до 11
		for(j=i+1;j<n;j++){
			if(i+j==n+N-1){ //==19
				Rep_val(&array[0], i, j);
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
	Replace_values_3 (&array[0], SIZE);
	Print_arr(&array[0], SIZE);
	
	
	return 0;
}
