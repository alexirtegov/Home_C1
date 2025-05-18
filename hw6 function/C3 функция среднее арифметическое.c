/*
C3-Среднее арифметическое
Написать функцию, которая возвращает среднее 
арифметическое двух переданных ей аргументов (параметров). 
int middle(int a, int b)

Формат входных данных:
Два целых не отрицательных числа

Формат результата:
Одно целое число
*/

#include <stdio.h>

int middle(int a, int b){
	int res = (a+b)/2;
	return res;
}


int main(int argc, char **argv)
{
	int A, B;
	
	if(scanf("%d %d", &A, &B)!=2){
		printf("Error");
		return 0;
	}
	
	int result = middle(A, B); //вызов функции middle(int a, int b)
	printf("%d", result);
	
	return 0;
}

