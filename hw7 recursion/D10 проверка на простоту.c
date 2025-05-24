/*
D10-Проверка на проостоту

Дано натуральное число N. 
Дано натуральное число n ≥ 1. 
Проверьте, является ли оно простым. 
Программа должна вывести слово YES, 
если число простое или NO в противном случае. 
Необходимо составить рекурсивную функцию и использовать ее.
int is_prime(int n, int delitel)

Формат входных данных:
Одно натуральное число.


Формат результата:
YES или NO
*/

#include <stdio.h>

int is_prime(int n, int delitel) { // 11 и 11
 
    if (delitel < n) {
		
	if (n % delitel == 0) {//11%2=1 11%4
        return 0;
    } 	
    return is_prime(n, delitel + 1);//11 и 4
    
    }
     
    
    else{
		return 1;
		
	}
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1 || N < 1) {
        printf("Error\n");
        return 1;
    }

    // Случаи 0 и 1 по определению не являются простыми.
    if (N < 2) {
        printf("NO\n");
    } else {
        // Запускаем рекурсивную проверку, начиная с делителя 2.
        if (is_prime(N, 2)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
