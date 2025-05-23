/*
D1-От 1 до N

Составить рекурсивную функцию, печать всех чисел от 1 до N

Одно натуральное число



Формат результата:
Последовательность чисел от 1 до введенного числа
*/

#include <stdio.h>

// Рекурсивная функция печати чисел от 1 до n
void  printFrom1_to_N(int n) {
    // Базовый случай: если n меньше 1, ничего не делаем
    if (n < 1) {
        return;
    }
    // Сначала печатаем все числа от 1 до n-1
    printFrom1_to_N(n - 1);//например n=3
    //  входим в  printFrom1_to_N(3),проверяем условие (3<1) и идем в printFrom1_to_N(3 - 1) или  printFrom1_to_N(2) мы не знаем что такое  printFrom1_to_N(2)
    // входим в  printFrom1_to_N(2),проверяем условие (2<1) и идем в printFrom1_to_N(2 - 1) или  printFrom1_to_N(1) мы не знаем что такое  printFrom1_to_N(1)
    // входим в  printFrom1_to_N(1),проверяем условие (1<1) и идем в printFrom1_to_N(1 - 1) или  printFrom1_to_N(0) мы не знаем что такое  printFrom1_to_N(0)
    // входим в  printFrom1_to_N(0),проверяем условие (0<1) выполнено начинаем движение обратно:
    // входим в  printFrom1_to_N(1) печатаем 1
    // входим в  printFrom1_to_N(2) печатаем 2
    // входим в  printFrom1_to_N(3) печатаем 3
    printf("%d ", n);
}

int main() {
    int N;
    // Чтение одного натурального числа
    if (scanf("%d", &N) != 1 || N < 1) {
        // Некорректный ввод — просто выходим
        return 0;
    }
    // Вызов рекурсивной функции
    printFrom1_to_N(N);
    // Перевод строки в конце вывода
    printf("\n");
    return 0;
}
