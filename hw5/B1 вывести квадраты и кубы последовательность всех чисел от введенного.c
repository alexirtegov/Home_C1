/*
 B1-Квадраты и кубы
 Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа.
 Число не превосходит 100.
 
Формат входных данных:
Одно целое число не превосходящее 100

Формат результата:
Для каждого из чисел от 1 до введенного числа напечатать квадрат числа и его куб.
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
	
	scanf("%d", &n);
	
	//вариант 1
	//~ int count=0;
	//~ while (n>0 && n<=100)
	//~ {
		
		//~ count++;
		//~ printf("%d %d %d\n", count, count*count, count*count*count);
		//~ n--;
		
	//~ }
	
	//вариант 2
	
	//~ if(n>0 && n<=100)
	//~ {
	//~ int count =1;
	//~ while (count<=n)	{
	//~ printf("%d %d %d\n", count, count*count, count*count*count);
	//~ count++;}
//~ }
//~ else{
	//~ printf("wrong number, it must be between 1-100 ");
//~ }
	
	//вариант 3 через for
	
		//~ for (int count=0; n>0 && n<=100; n--){
		//~ count++;
//~ printf("%d %d %d\n", count, count*count, count*count*count);
//~ }
	
	//вариант 3.1 через for
	
	if(n>0 && n<=100)
	{
	for (int count=1; count<=n; count++)
	{
	printf("%d %d %d\n", count, count*count, count*count*count);
}
}
	return 0;
}

