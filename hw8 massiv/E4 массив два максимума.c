/*
E4-Два максимума

Считать массив из 10 элементов и найти в нем 
два максимальных элемента и напечатать их сумму.




Формат входных данных:
10 целых чисел через пробел


Формат результата:
Сумма двух максимальных элементов.
*/



#include <stdio.h>
#define SIZE 10

void Input (int array[], int n)
{
	for(int i = 0; i<n; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
			return;
		}
	}
}

int Max1_array (int array[], int n)
{
	int max= array[0];
	
	for(int i=0;i<n; i++){
		if(max<array[i]){
			max=array[i];
		}
		
	}
	return max;
}

int Max2_array (int array[], int n, int max1)
{
	int count_max = 0;
	for(int i=0; i<n; i++){
		if(array[i]==max1){
			count_max++;
		}
	}
	
	if(count_max>=2){
		return max1;
	}
	
	int i=0;
	while (i<n && array[i]==max1){ //200 100 5 6 .... i=1
		i++;//мы получем значение i равным количеству членов массива равных max1
	}
	
	if(i==n){//если весь ряд членов будет одинаков и равен max1, вернем max1
		return max1;
	}
	
	int max2 = array [i];//i=1 array [1]=100
	
	for(++i;i<n; i++){
		if(array[i]!=max1 && array[i]> max2){ //5!=200 && 5>200
			max2=array[i];//остается 100
		}
		
	}
	return max2;
}


int main(int argc, char **argv)
{
	int array[SIZE] = {0};
	Input (&array[0], SIZE);
	int Max1 = Max1_array (&array[0], SIZE);
	int Max2 = Max2_array (&array[0], SIZE, Max1);
	
	printf("%d", Max1 + Max2);
	
	return 0;
}

