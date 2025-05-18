/*
C6-Сколько зерен на шахматной доске
Когда создатель шахмат, древнеиндийский мудрец и математик Сисса бен Дахир, 
показал своё изобретение Правителю страны, тому так понравилась игра, 
что он позволил изобретателю право самому выбрать награду. 
Мудрец попросил у Повелителя за первую клетку шахматной доски заплатить ему 
одно зерно риса, за второе — два, за третье — четыре и т. д., 
удваивая количество зёрен на каждой следующей клетке. 
Помоги повелителю сосчитать сколько зерен на какой клетке лежит.
Необходимо составить функцию, которая определяет, 
сколько зерен попросил положить на N-ую клетку изобретатель шахмат 
(на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)

Формат входных данных:
Цлое число от 1 до 64

Формат результата:
Одно целое число. Количество зерен на данной клетке.
*/


#include <stdio.h>

unsigned long long f_grain(int n){
	unsigned long long GRAIN=1;
	unsigned long long SUM=1;
	for(int i=1;i<n;i++){
	GRAIN=GRAIN*2;
	SUM+=GRAIN;
}

return GRAIN;


}

unsigned long long f_sum(int N){
	unsigned long long GRAIN=1;
	unsigned long long SUM=1;
	for(int i=1;i<N;i++){
	GRAIN=GRAIN*2;
	SUM+=GRAIN;
}


return SUM;

}

int main(int argc, char **argv)
{
	int n;
	unsigned long long grain;
	unsigned long long SUM;
	
	if(scanf("%d", &n)!=1){
		printf("Error input");
		return 1;
	}
	
	//проверяем диапазон допустимости
	if (n<1 || n>64){
		printf("The cell number must be between 1 and 64.");
		return 1;
	}
	 grain = f_grain(n);
	 printf("\ngrains = %llu\n", grain);
	 
	 SUM = f_sum(n);
	 printf("\ngrains sum = %llu\n", SUM);
	
	return 0;
}

