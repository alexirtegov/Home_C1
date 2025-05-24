/*
D7-Печать от N до 1

Составить рекурсивную функцию, печать всех чисел от N до 1.

Формат входных данных:
Одно натуральное число


Формат результата:
Последовательность целых чисел от введенного числа до 1, через пробел.
*/


#include <stdio.h>

void print_from_N_to_1(int N)
{
	if(N<1){
		return;
	}
	printf("%d ", N);
	print_from_N_to_1(N-1);
	
		
}

int main(int argc, char **argv)
{
	int N;
	if(scanf("%d",&N)!=1){
		printf("Error");
		return 1;
	}
	
	print_from_N_to_1(N);
	
	
	return 0;
}

