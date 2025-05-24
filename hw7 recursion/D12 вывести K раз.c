/*
D12-Вывести k раз

Дана монотонная последовательность, 
в которой каждое натуральное число k 
встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
Выведите первые n членов этой последовательности.

Формат входных данных:
Одно натуральное число.


Формат результата:
Последовательность целых чисел.
*/


#include <stdio.h>

// Рекурсивно печатает первые n элементов 
// монотонной последовательности 1, 2 2, 3 3 3, …,
// начиная с блока k (число k печатаем k раз).
void print_first_n(int n, int k) {
    if (n <= 0)
        return;                   // больше печатать нечего

    // Сколько раз мы можем здесь напечатать текущее k:
    int times = n < k ? n : k;
    for (int i = 0; i < times; i++) {
        printf("%d ", k);
    }

    // Рекурсивно печатаем оставшиеся n - times элементов,
    // переходя к следующему числу k+1
    print_first_n(n - times, k + 1);
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1 || N < 1) {
        printf("Error\n");
        return 1;
    }
    print_first_n(N, 1);
    return 0;
}

//вариант 2 через цикл for

//~ #include <stdio.h>

//~ void print_monotonic_sequence(int N) {
    //~ int printed = 0;
    //~ for (int k = 1; printed < N; k++) {
        //~ for (int i = 0; i < k && printed < N; i++) {
            //~ printf("%d ", k);
            //~ printed++;
        //~ }
    //~ }
//~ }

//~ int main(void) {
    //~ int N;
    //~ if (scanf("%d", &N) != 1 || N < 1) {
        //~ printf("Error\n");
        //~ return 1;
    //~ }
    //~ print_monotonic_sequence(N);
    //~ return 0;
//~ }
