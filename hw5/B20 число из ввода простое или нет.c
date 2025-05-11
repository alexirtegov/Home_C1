/*
B20-Простое число
Проверить число на простоту.

Простые числа — это натуральные числа, 
имеющие ровно два различных делителя: единицу и само это число. 

Формат входных данных:
Натуральное число

Формат результата:
Если число является простым напечатать YES, иначе NO
*/


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1 || number<0){
		printf("wrong input");
		return 0;
		
		
	}
	if (number == 1) {
        printf("NO");
        return 0;
    }
    
	int prime_n=number;
	for(int i =2;i<number;i++){ //мы будем проверять числа на деление на число находящееся в интервале от 2 до 9, если делится - не простое
			if(prime_n%i==0 || (prime_n==1)){
			printf("NO");
			return 0;
		}
	
	}
	printf("YES");
	
	return 0;
}

