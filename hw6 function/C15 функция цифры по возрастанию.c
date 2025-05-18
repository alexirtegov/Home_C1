/*
C15-Цифры по возрастанию

Составить функцию логическую функцию, 
которая определяет, верно ли, что в заданном числе 
все цифры стоят по возрастанию. 
Используя данную функцию решить задачу. 
int grow_up(int n)



Формат входных данных:
Одно целое не отрицательное число

Формат результата:
Ответ YES или NO
*/


//для решения использовал алгоритм задачи B10 из hw5
#include <stdio.h>

void compare (int number)
{
	for(int current_num, next_num;number>0;){//возьмем пример 746
		
		current_num=number%10;//1-я иттерация 746%10=6  2-я иттерация 74%10=4
		number=number/10;//1-я иттерация 746/10=74      2-я иттерация 74/10=7
		next_num=number%10;//1-я иттерация 74%10=4      2-я иттерация 7%10=7
		
		if(next_num>=current_num){//1-я иттерация если 4>6 выходим из цикла (ложь)   2-я иттерация 7>4 истина -выход из цикла 
			printf("NO"); //2-я иттерация сработала - печать НЕТ
			return;
		}
		
}		
	printf("YES");
}

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input");
		return 0;
	}
	
	if(number<0){
		number=-number;
	}
	
	compare (number);
	
	return 0;
}

