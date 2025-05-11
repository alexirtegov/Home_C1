/*
B9-Все цифры четные
Ввести целое число и определить, 
верно ли, что все его цифры четные.

Формат входных данных:
Одно целое число

Формат результата:
Ответ: YES или NO
*/


#include <stdio.h>




int main(int argc, char **argv)
{

int number;

if(scanf("%d", &number)!=1){
	printf("wrong input");
	return 0;
}

if(number<0){
	number = - number;
}
	
	for(int search; number>0;){
		search=number%2;
		number=number/10;
		if(search!=0){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	
	
	
	return 0;
}

