/*
E1-Среднее арифметическое

Ввести c клавиатуры массив из 5 элементов, 
найти среднее арифметическое всех элементов массива.


Формат входных данных:
5 целых не нулевых чисел через пробел


Формат результата:
Одно число в формате "%.3f"
*/



#include <stdio.h>


#define SIZE 5

void Input (int massive[], int n)//для массива из 5ти элементов 
{
	for(int i =0;i<n; i++){
		
		if(scanf("%d", &massive[i])!=1){
			printf ("Error\n");
			return;
		}
	}
		return;
}

double Arithmetic_mean(int massive[], int n)
{
	int sum=0;
	int i; // сюда мы посчитаем делитель для нахождения среднего
	for(i =0;i<n; i++){
		sum +=massive[i];
	}
	double arithmetic_sum=0;
	arithmetic_sum = (double)sum/i;
	
	return arithmetic_sum;
		
}


int main(int argc, char **argv)
{
	int massive [SIZE] ={0};
	Input(&massive[0], SIZE); //вызываем функцию, куда передаем указатель на первое значение, а также значение SIZE равное 5
	
	printf("%.3f", Arithmetic_mean(massive, SIZE));
	
	return 0;
}

