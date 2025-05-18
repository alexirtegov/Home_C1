/*
C14-Сумма цифр четна

Составить функцию логическую функцию, которая определяет, 
верно ли, что сумма его цифр – четное число. 
Используя эту функцию решить задачу.


Формат входных данных:
Одно целое не отрицательное число

Формат результата:
Ответ YES или NO
*/



#include <stdio.h>

void sum_even_number(int N){
	
	int number = N;
	int sum=0;
	for(;number>0;){
		sum += number%10;
		number /=10;
	}
	//~ return sum;
	if (sum%2==0){
		puts ("YES");
	}
	else{
		puts ("NO");
	}
}

int main(int argc, char **argv)
{
	int N; //наше целое не отрицательное число
	
	if(scanf("%d", &N)!=1||N<0){
		printf("error input, N must be >0");
		return 1;
	}
	
	//~ int sum = sum_even_number(N);
	//~ printf("%s", sum%2==0?"YES":"NO");
		
		sum_even_number(N);
	
	return 0;
}

