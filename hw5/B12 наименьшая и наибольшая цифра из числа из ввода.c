/*
B12-Наименьшая и наибольшая цифра
Организовать ввод натурального числа с клавиатуры. 
Программа должна определить наименьшую и наибольшую цифры, 
которые входят в состав данного натурального числа.

Формат входных данных:
Целое неотрицательное число

Формат результата:
Две цифры через пробел. 
Сначала наименьшая цифра числа, затем наибольшая.
*/

#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input");
		return 0;
	}
	
	if(number==0){
	printf("%d", number);
	return 0;
}
	//вариант 1 с двумя циклами и тернарным оператором
	
	//~ int cur_min, abs_min=9, min_number=number;
	//~ for (;min_number>0;){      //например 26832>0
		//~ cur_min=min_number%10; //2
		//~ min_number=min_number/10;//2683
		
		//~ abs_min=(abs_min<=cur_min)?(abs_min):(cur_min);//2
			
	//~ }
	
	//~ int cur_max, abs_max=0, max_number=number;
	//~ for (;max_number>0;){      //например 26832>0
		//~ cur_max=max_number%10; //2
		//~ max_number=max_number/10;//2683
		
		//~ abs_max=(abs_max>=cur_max)?(abs_max):(cur_max);//2
			
	//~ }
	
	//вариант 2 в одном цикле
	
	int abs_min=9;
	int abs_max=0;
	for(int cur;number>0;){
		cur=number%10;
		number=number/10;
		if(cur<abs_min){
			abs_min=cur;
		}
		if(cur>abs_max){
			abs_max=cur;
		}
		
	}
	
	printf("%d %d",abs_min, abs_max);
	
	
	return 0;
}

