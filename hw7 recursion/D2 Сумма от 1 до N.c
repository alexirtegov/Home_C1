/*
D2-Сумма от 1 до N

Составить рекурсивную функцию, 
которая определяет сумму всех чисел от 1 до N

Формат входных данных:
Одно натуральное число


Формат результата:
Сумма чисел от 1 до введенного числа
*/



#include <stdio.h>

int summa_from_1_to_N(int N){ //ДЛЯ N=4   это 4+3+2+1 =10
	printf("%d\n", N);
	if(N<=1){
		return 1;
	}
	int f =N + summa_from_1_to_N(N-1); 
	printf("%d+ summa_from_1_to_%d=%d\n",N, N-1, f);
	return f;
}
//1) входим в summa_from_1_to_N(4) печать 4, проверка условия 4<=1, int f =4 + summa_from_1_to_N(3), ищем что такое summa_from_1_to_N(3)
//2) входим в summa_from_1_to_N(3) печать 3, проверка условия 3<=1, int f =3 + summa_from_1_to_N(2), ищем что такое summa_from_1_to_N(2)
//3) входим в summa_from_1_to_N(2) печать 2, проверка условия 2<=1, int f =2 + summa_from_1_to_N(1), ищем что такое summa_from_1_to_N(1)

//4) входим в summa_from_1_to_N(1) печать 1, проверка условия 1<=1, выполнено, мы возвращаем (return 1) на место summa_from_1_to_N(1)

//5) входим в summa_from_1_to_N(2) печать 2+1=3, так как int f =2 + summa_from_1_to_N(1) вместо summa_from_1_to_N(1) можем подставить 1
//6) входим в summa_from_1_to_N(3) печать 3+2=6, так как int f =3 + summa_from_1_to_N(2) вместо summa_from_1_to_N(2) подставить 3
//7) входим в summa_from_1_to_N(4) печать 4+3=10, так как int f =4 + summa_from_1_to_N(3) вместо summa_from_1_to_N(3) подставить 6

int main(int argc, char **argv)
{
	int n;
	
	if (scanf("%d", &n)!=1){
		printf("Error");
		return 1;
	}
	if (n<0){
		printf("Error");
		return 1;
	}
	
	int result = summa_from_1_to_N(n);
	printf("%d", result);
		
	return 0;
}

