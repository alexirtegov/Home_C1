/*
D17-Функция Аккермана

Функция Аккермана определяется рекурсивно 
для неотрицательных целых чисел m и n следующим образом:

A(0, m)        = m+1
A(n+1, 0)      =A(n,1) или (n-1, 1)
A(n+1, m+1)    =A(n, A(n+1, m)) или A(n-1, A(n, m-1)

Реализуйте данную функцию по прототипу

Формат входных данных:
Даны неотрицательные целые числа m и n


Формат результата:
Одно целое число
*/


#include <stdio.h>


/* 
если n = 0, то A(0,m)=m+1.
Рекурсия для m = 0 и n > 0:   A(n,0)=A(n−1,1). 
Общий рекурсивный случай для n > 0 и m > 0:  A(n,m)=A(n−1, A(n,m−1)).
  */
int ackermann(int n, int m) {
    if (n == 0) {
        // A(0, m) = m + 1
        return m + 1;
    }
    if (m == 0) {
        // A(n, 0) = A(n-1, 1)  для n > 0
        return ackermann(n - 1, 1);
    }
    // A(n, m) = A(n-1, A(n, m-1))  для n > 0, m > 0
    return ackermann(n - 1, ackermann(n, m - 1));
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        // Неправильный ввод
        printf("Error reading input\n");
        return 1;
    }
    // По условию n и m неотрицательны
    if (n < 0 || m < 0) {
        printf("n and m must be non-negative\n");
        return 1;
    }
    int result = ackermann(n, m);
    printf("%d\n", result);
    return 0;
}
