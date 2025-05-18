/*
C9-Факториал

Составить функцию вычисления N!. 
Использовать ее при вычислении факториала 
int factorial(int n)

Формат входных данных:
Целое положительное число не больше 20

Формат результата:
Целое положительное число
*/

//Например, факториал числа 5 будет равен 1 × 2 × 3 × 4 × 5 = 120.
#include <stdio.h>


int factorial (int N){
	int fac=1;
	for(int i=1;i<=N;i++){
		fac*=i; //1*1 = 1*2 =2*3=6*4=24=24*5=120
	}
	return fac;
}


int main(int argc, char **argv)
{
	int N;
	
	if (scanf("%d", &N)!=1|| N<0){
		printf("Error input");
		return 1;
	}
	
	if (N>20){
		printf("Error input, N must be from [0 to 20]");
		return 1;
	}
	
	int result = factorial(N);
	printf("%d", result);
		
		
	return 0;
}

