/*
B2-Квадраты от А до В
Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.

Формат входных данных:
Два целых числа по модулю не больше 100

Формат результата:
Квадраты чисел от a до b.
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b;
	
	if(scanf("%d %d", &a, &b) !=2){
		printf("wrong input");
		return 0;
	}
	
	
	if(a<=b && b<100 && a<100) 
	
	
	//вариант 1 через while
		//~ {
	//~ while(a<=b){
	//~ printf(" %d", a*a);
	//~ a++;
//~ }
//~ }
	
	
	//вариант 2 через for
	{
		for(;a<=b;a++)
		printf(" %d", a*a);
	}
	
	
	else
	printf("wrong input");
	
	return 0;
}

