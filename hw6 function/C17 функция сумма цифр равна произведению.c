/*
C17-Сумма цифр равна произведению

Составить логическую функцию, которая определяет, 
верно ли, что в заданном числе сумма цифр 
равна произведению. int is_happy_number(int n)




Формат входных данных:
Одно целое не отрицательное число.


Формат результата:
Ответ YES или NO
*/


#include <stdio.h>

int is_happy_number(int n)
{
	int sum=0, multip=1;
	for(; n>0;){
		sum+=n%10;
		multip*=n%10;
		n/=10;
	}
	if (sum==multip){
		return 1;
	}
	else{
		return 0;
	}
}

int main(int argc, char **argv)
{
	int n;
	
	if(scanf("%d", &n)!=1){
		printf("wrong input");
		return 1;
	}
	
	printf("%s", is_happy_number(n) ? "YES" : "NO");
	return 0;
}

