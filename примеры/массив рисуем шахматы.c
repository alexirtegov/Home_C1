#include <stdio.h>

#define SIZE 8  // Можно выбрать любой размер

int main() {
    char* color[SIZE][SIZE]; //Это двумерный массив указателей на char.

    // Заполняем массив "черный" и "белый" по принципу шахматной доски
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if ((i + j) % 2 == 0)
                color[i][j] = "black";
            else
                color[i][j] = "White";
        }
    }

    // Выводим всю таблицу
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%8s ", color[i][j]); // 8 символов — чтобы красиво выровнять.
        }
        printf("\n\n\n");
    }
    return 0;
}
