/*
E16-Чаще всего

Дан массив из 10 элементов. 
Определить, какое число в массиве встречается чаще всего. 
Гарантируется, что такое число ровно 1.


Формат входных данных:
10 целых чисел через пробел
4  1  2  1  11  2  34  11  0  11

Формат результата:
Одно число, которое встречается чаще других.
11

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
	
	
	int max=0;
	int result =0;
	
	for(int i=0; i<SIZE; i++){
		int count=0;
		for(int j=i+1; j<SIZE; j++){
			if(array[i]==array[j]){
				count++;
			}
		}
		if(max<count){
			max=count;
			result=array[i];
		}
	}
	printf("%d", result);
	
	return 0;
}
