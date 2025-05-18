/*
C11-НОД

Составить функцию, которая определяет 
наибольший общий делитель двух натуральных 
и привести пример ее использования. 
int nod(int a, int b)

Формат входных данных:
Два целых положительных числа

Формат результата:
Одно целое число - наибольший общий делитель.
*/

//для решения взял свой код решения задачи B16 НОД

#include <stdio.h>

int nod(int a, int b){
		for(;a!=b;){
		if(a>b){
			a=a-b;
		}else{
			b=b-a;
		}
	}
	return a;
}

int main(int argc, char **argv)
{
	int a, b;
	
	if(scanf("%d %d", &a, &b)!=2){
		printf("Error input");
		return 1;
	}
	
	
		if(a<0||b<0){
		printf("wrong input, 'a' and 'b' must be >0");
		return 1;
		}
		
		
		int NOD= nod(a, b);
		printf("NOD= %d", NOD);
		
		
		
	return 0;
}

