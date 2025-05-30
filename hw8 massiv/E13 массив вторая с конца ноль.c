/*
E13-Вторая с конца ноль

Считать массив из 10 элементов и отобрать в другой массив все числа, 
у которых вторая с конца цифра (число десятков) – ноль.


Формат входных данных:
10 целых чисел через пробел
40 105 203 1 14 1000 22 33 44 55

Формат результата:
Целые числа через пробел, 
у котороых вторая с конца цифра - ноль
105 203 1 1000
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

int Replace(int array[], int arr[], int n)
{
	int count=0;
	for(int i = 0; i<n; i++){
		if((array[i]/10)%10 == 0){
			arr[count] = array[i];
			count ++;
			
		}
	}
	return count;
}



void Print_arr(int arr[], int n)
{
	for(int i =0;i<n;i++){
		printf("%d ", arr[i]);
	}
}



int main(int argc, char **argv)
{
	int array[SIZE] ={0};
	int arr[SIZE]={0};
	
	Input(&array[0], SIZE);
	
	
	int count = Replace(&array[0], &arr[0], SIZE);
	
	
	

	
	Print_arr(&arr[0], count);
	
	
	return 0;
}
