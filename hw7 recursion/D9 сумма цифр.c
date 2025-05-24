/*
D9-Сумма цифр

Дано натуральное число N. 
Вычислите сумму его цифр. 
Необходимо составить рекурсивную функцию.
int sum_digits(int n)

Формат входных данных:
Одно натуральное число.


Формат результата:
Целое число - сумма цифр введенного числа.
*/


#include <stdio.h>

int print_sum_number_of_N (int N)//N=123
{
	if(N==0){
		return 0;
	}
	//~ printf("%d\n", N);
	int result=0;
	result = (N%10) + print_sum_number_of_N (N/10);
	//123!==0, 3 + print_sum_number_of_N(12) мы не знаем чему равна print_sum_number_of_N(12)
	//12!=0, 2 + print_sum_number_of_N(1) мы не знаем чему равна print_sum_number_of_N(1)
	//1!=0, 1 + print_sum_number_of_N(0) мы не знаем чему равна print_sum_number_of_N(0)
	//0==0 мы выполняем условие и возвращаем 0 (return 0) в функцию print_sum_number_of_N(0) делая ее равной 0
	// 1 + print_sum_number_of_N(0) это 1+0 = 1
	// 2 + print_sum_number_of_N(1) это 2+1 = 3
	// 3 + print_sum_number_of_N(12) это 3 +3 =5
	
	//~ printf("%d\n", result);
	return result;
	
	
}


int main(int argc, char **argv)
{
	int N;
	if(scanf("%d",&N)!=1){
		printf("Error");
		return 1;
	}
	
	int sum = print_sum_number_of_N (N);
	printf("%d", sum);
	
	return 0;
}

