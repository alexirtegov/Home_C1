/*
D4-В прямом порядке

Дано натуральное число N. 
Выведите все его цифры по одной, в прямом порядке, 
разделяя их пробелами или новыми строками. 
Необходимо реализовать рекурсивную функцию.
void print_num(int num)

Формат входных данных:
Одно не отрицательное целое число


Формат результата:
Все цифры числа через пробел в прямом порядке.
*/

#include <stdio.h>
void print_num(int num){
	if(num==0){
	return;
}
	

	print_num(num/10);
	printf("%d ", num%10);	
}
	


int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input\n");
		return 0;
	}
	
	if (number == 0) {
        printf("0\n");
     }else{
		 print_num(number);
		 printf("\n");
	 }
	 
	return 0;
}

