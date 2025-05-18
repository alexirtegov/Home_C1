/*
C5-Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел 
от 1 до N и привести пример ее использования.

Формат входных данных:
Одно целое положительное число N

Формат результата:
Целое число - сумма чисел от 1 до N
*/


#include <stdio.h>

int f(int X){
	int sum=0;
	for(int i=1;X>=i;i++){
		sum+=i;
	}
	return sum;
}

int main(int argc, char **argv)
{
	
	int x;
	
	if(scanf("%d", &x)!=1){ //если при первичнов в воде ошибка или ноль, сразу выход
		printf("Error");
		return 0;
	}
	
	int result = f(x);
	
	printf("%d", result);
	
	
	return 0;
}

