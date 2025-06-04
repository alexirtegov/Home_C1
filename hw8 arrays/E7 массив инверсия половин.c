/*
E7-Инверсия половин

Считать массив из 10 элементов и 
выполнить инверсию отдельно для 1-ой и 2-ой 
половин массива. 
Необходимо изменить считанный массив и 
напечатать его одним циклом.

Формат входных данных:
10 целых элементов массива через пробел.


Формат результата:
10 целых элементов массива через пробел.
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



void Replace_values_1 (int array[], int n)
{
	int i, j, N=n/2;
	for(i=0; i<N; i++){ // 1 2 3 4 5 N 6 7 8 9 10
		for(j=i+1;j<N;j++){
			if(i+j==N-1){
				Rep_val(&array[0], i, j);
			}
		}
	}
}
	
	
	
void Replace_values_2 (int array[], int n)
{	
	int a, b, N=n/2;
	for(a=N; a<n; a++){ // 1 2 3 4 5 N 6 7 8 9 10
		for(b=a+1;b<n;b++){
			if(a+b==n-1+N){
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

