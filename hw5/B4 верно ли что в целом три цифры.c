/*
B4-Ровно три цифры

Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.

Формат входных данных:
Целое положительное число

Формат результата:
Одно слов: YES или NO
 */



#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number) !=1){
		printf("wrong number");
		return 0;
	}
	
	
	/* Варинт 1 через установление интервала допустимости:
	решение строил исходя из того, 
	что самое наименьшее 3-х значное число это 100, а наибольшее 999*/
	
	//~ printf("%s",number>99 && number<1000?"YES":"NO");//через тернарный оператор
	
	
	
	//вариант 2 через цикл
	if(number<0){
		printf("NO");
		return 0;
}
		
		int count;
		for(count=0;number>0;count++){
		number=number/10;// число 123:10=number=12>0; 12:10=number=1>0; 1:10=number=0 условие number>0 нарушено через три итерации
	}
	
	
		if (count == 3) {
        printf("YES");
    } 
    
    else {
        printf("NO");
    }

		
		
		
	return 0;
}

