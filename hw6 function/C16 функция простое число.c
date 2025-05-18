/*
C16-Простое число

Составить функцию логическую функцию, 
которая определяет, верно ли, что число простое. 
Используя функцию решить задачу. 
int is_prime(int n)



Формат входных данных:
Одно целое не отрицательное число.


Формат результата:
Ответ YES или NO
*/

//код взял из своего решения B20 из hw5 

#include <stdio.h>

void prime_number (int number)
{
		if(number<=1){
			printf("NO");
			return;
		}
			
		
int prime_n=number;
for(int i =2;i<number;i++){ //мы будем проверять числа на деление на число находящееся в интервале от 2 до 9, если делится - не простое
if(prime_n%i==0 || (prime_n==1)){
printf("NO");
return;
}

}
printf("YES");
}

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        printf("wrong input");
        return 1;
    }
    // по условию «одно целое неотрицательное число»
    if (number < 0) {
        printf("wrong input");
        return 1;
    }

prime_number(number);

return 0;
}
