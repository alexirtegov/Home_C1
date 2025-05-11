/*
B13-Количество четных и нечетных цифр
Посчитать количество четных и нечетных цифр числа.

Формат входных данных:
Одно целое неотрицательное число.

Формат результата:
Два числа через пробел. Количество четных и нечетных цифр в числе.
*/


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input");
		return 0;
		
		
		
	}
		if(number==0){
	printf("1 0");
	return 0;
}
	
	int even=0, n_even=0;
	
	for(int cur; number>0;){
		cur=number%10;
		number=number/10;
			if(cur%2==0){
			even++;
		}
		else{
			n_even++;
		}
	}
	
	printf("%d %d", even, n_even);
	
	return 0;
}

