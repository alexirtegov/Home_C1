/*
B5-Сумма цифр

Ввести целое число и найти сумму его цифр.

Формат входных данных:
Одно целое число большее или равное нулю.

Формат результата:
Одно число - сумма цифр
 */



#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	
	if(scanf("%d", &number)!=1){
		printf("wrong number");
		return 0;
	}
	if(number < 0){
		printf("wrong number");
		return 0;
	}	
	
/*
чтобы найти решенеие задачи нам необходим цикл %10 и /10. 
Например возьмем число 234
1) sum=0+234%10=4 
   234/10=23
   23>0 продолжаем
2) sun=4+23%10=4+3=7
   23/10=2
   2>0 продолжаем
3) sum=7+2%10=7+2=9
   2/10=0выходим из условия
 */
	int sum=0;
	for(;number>0;){
		sum+=number%10;
		number=number/10;
			}
	
	printf("%d",sum);
	
	return 0;
}

