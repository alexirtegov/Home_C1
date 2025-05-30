/*
E11-Отсортировать по последней цифре

Считать массив из 10 элементов и 
отсортировать его по последней цифре.


Формат входных данных:
10 целых чисел через пробел
14  25  13  30  76  58  32  11  41  97

Формат результата:
Этот же массив отсортированный по последней цифре
30  11  41  32  13  14  25  76  97  58

*/

//нужно два цикла в первом мы находими минимум и сохраняем в него соответствующее значение array[]
//во втором цикле мы сначала делаем замену текущего члена на найденный 

#include <stdio.h>
#define SIZE 10


void Input (int array[], int n)
{
	for(int i = 0; i<n; i++){
		if(scanf("%d", &array[i])!=1){
			printf("Error");
		}
	}
}

void Sort(int array[], int n)
{
    for (int j = 0; j < n - 1; j++) { 
       
        int min_index = j;
        for (int i = j + 1; i < n; i++) { 
            if ((array[i] % 10) < (array[min_index] % 10)) {
                min_index = i;
            }
        }
        // меняем array[j] и array[min_index]
        if (min_index != j) {
            int tmp = array[j];
            array[j] = array[min_index];
            array[min_index] = tmp; 
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
	int array[SIZE];
	Input(&array[0], SIZE);
	Sort(&array[0], SIZE);
	
	
	Print_arr(&array[0], SIZE);
	
	
	return 0;
}

