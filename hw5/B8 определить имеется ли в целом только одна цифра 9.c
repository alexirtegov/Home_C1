/*
B8-Ровно одна цифра 9
Ввести целое число и определить, 
верно ли, что в нём ровно одна цифра «9». 

Формат входных данных:
Одно целое число

Формат результата:
Ответ: YES или NO
 */



#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	
	if(scanf("%d", &number) !=1){
		printf("wrong input");
		return 0;
	}
	
	if(number<0){
		number = -number;
		}
	
	
	//вариант 1. Используем вложенный цикл для поиска второй девятки. Работает но получился сложным
	
	//~ for(int search;number>0;){ //возьмем к примеру число 129
		//~ search=number%10; //129%10=search=9
		//~ number=number/10;//129/10=number=12
		
		//~ if(search==9){//у нас первый кандидат 9, проваливаемся во внутренний цикл
			//~ for(int search_second, number_second=number; number_second>0;){//для того чтобы перебраться оставшиеся два числа=12 и понять есть ли число 9, вводим вспомогательную перменную number_second
			//~ search_second=number_second%10; //12%10=number_second=2
			//~ if(search_second==9){//сравниваем 2 с числом 9, совпадения нет, идем по циклу дальше. (было бу совыпадения цикл завершился принтом NO)
				//~ printf("NO");
				//~ return 0;
			//~ }
			//~ number_second=number_second/10; //12/10 = number_second
						
		    //~ }
		//~ }
		//~ if(search==9){ //мы прошли по внутреннему циклу и не нашли второй 9, если первая search была 9 ваводим принт YES
		//~ printf("YES");
		//~ return 0;
	//~ }
	//~ }
	
	//~ printf("NO"); //если мы прошли по циклу и не нашли 9, выводим принт NO
	
	
	//вариант 2 будем считать 9-ки, если одна выводить -да, если больше чем одна выводить -нет
	int count_9=0;
	for(int search; number>0;){
		search=number%10;
		number=number/10;
		if(search==9){
			count_9=count_9+1;
		}
		
	}
	printf("%s", (count_9==0||count_9>1)?"NO":"YES");
	
	
	
	return 0;
}

