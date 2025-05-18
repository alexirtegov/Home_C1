/*
C2-Степень числа
Составить функцию, возведение числа N в степень P. 
int power(n, p) и привести пример ее использования.

Формат входных данных:
Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0

Формат результата:
Одно целое число
*/


#include <stdio.h>

int power(int n, int p){
	int raising=1;// в raising будем накапливать произведение, т.е. степень
	for(int i=1;i<=p;i++){
		raising=raising*n;
	}
	return raising; //возвращаем накопленное значение в result
}


int main(int argc, char **argv)
{
	int N, P;
	
	if(scanf("%d %d", &N, &P)!=2){
		printf("Error");
		return 0;
	}
	
	int result = power(N, P); //вызов функции power(int n, int p)
	printf("%d", result);
	
	
	return 0;
}

