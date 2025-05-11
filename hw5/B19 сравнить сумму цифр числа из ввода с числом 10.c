/*
B19-Сумма цифр равна 10
Ввести натуральное число и определить, 
верно ли, что сумма его цифр равна 10.

Формат входных данных:
Одно натуральное число

Формат результата:
YES или NO
*/



#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1 || number<0){ //ввели число 19
		printf("wrong input");
		return 0;
	}
	
	int sum=0, i=number; //i теперь 19
	for (;i>0;){
	sum+=i%10; //0+9=9     9+1=10
	i/=10; //19/10=1       1/10=0
	}
	
	printf("%s", sum==10?"YES":"NO");
	
	
	
	
	return 0;
}

