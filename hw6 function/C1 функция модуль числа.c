/*
C1-Модуль числа
Составить функцию, модуль числа и 
привести пример ее использования.

Формат входных данных:
Целое число

Формат результата:
Целое не отрицательное число
*/



#include <stdio.h>

int my_abs(int x){
	if (x<0){
	return -x;}
	else{
	return x;}

}

int main(int argc, char **argv)
{
	int N;
	if(scanf("%d", &N)!=1){
		printf("Error");
		return 0;
	}
	
	int result = my_abs(N);
	printf("%d", result);
	
	return 0;
}

