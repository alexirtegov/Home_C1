/*
D8-Числа от A до B

Составить рекурсивную функцию, 
Выведите все числа от A до B включительно, 
в порядке возрастания, если A < B, 
или в порядке убывания в противном случае.

Формат входных данных:
Два целых числа через пробел.


Формат результата:
Последовательность целых чисел.
*/

#include <stdio.h>

void print_from_A_to_B(int A, int B)
{
    // Базовый случай: A == B
    if (A == B) {
        printf("%d", A);
        return;
    }
    // Общий случай: печатаем текущую A и спускаемся дальше
    printf("%d ", A);
    if (A < B) {
        print_from_A_to_B(A + 1, B);
    } else {
        print_from_A_to_B(A - 1, B);
    }
}

int main(int argc, char **argv)
{
	int A, B;
	if(scanf("%d %d",&A, &B)!=2){
		printf("Error");
		return 1;
	}
	
	print_from_A_to_B(A, B);
	
	
	return 0;
}

