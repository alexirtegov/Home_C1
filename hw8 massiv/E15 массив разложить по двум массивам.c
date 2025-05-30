/*
E15-Разложить по двум

Считать 10 чисел в диапазоне от -500 до 500 и разложить 
по двум массивам: в одни помещать только положительные, 
во второй - только отрицательные. Числа, равные нулю, игнорировать. 
Вывести на экран все элементы обоих массивов.




Формат входных данных:
10 целых чисел через пробел
5 -4 0 1 4 -3 -3 3 0 2

Формат результата:
Сперва положительные числа, 
потом отрицательыне числа, через пробел.
5 1 4 3 2 -4 -3 -3

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

void Print_all(int arr1[], int arr2[], int count1, int count2)
{
	for(int i =0; i<count1; i++){
		printf("%d ", arr1[i]);
	}
	for(int i =0; i<count2; i++){
		printf("%d ", arr2[i]);
	}
}

int Sort_array_to_arr1(int array[], int arr1[], int n) //сюда положительные члены массива, ноль пропускаем
{
	int count1=0;
	for(int i =0; i<n; i++){
		if(array[i]>0){
			arr1[count1]=array[i];
			count1++;
		}
	}
	return count1;
}

int Sort_array_to_arr2(int array[], int arr2[], int n) //сюда отрицательные члены массива, ноль пропускаем
{
	int count2=0;
	for(int i =0; i<n; i++){
		if(array[i]<0){
			arr2[count2]=array[i];
			count2++;
		}
	}
	return count2;
}


int main(int argc, char **argv)
{
	int array[SIZE]={0};
	Input(&array[0], SIZE);
	
	int arr1[SIZE]= {0};//для положительных
	int arr2[SIZE]= {0}; //для отрицательных
	
	int count1 = Sort_array_to_arr1(&array[0], &arr1[0], SIZE);
	int count2 = Sort_array_to_arr2(&array[0], &arr2[0], SIZE);
	
	
	Print_all(&arr1[0], &arr2[0], count1, count2);
	
	return 0;
}

