/*
    Ввести пять чисел и найти  наименьшее из них.
    
    Формат входных данных:
    Пять целых чисел
    
    Формат результата:
    Одно целое число


 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//вариант 1
	
	int a, b, c, d, e, min;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	min = a;
	


if(b<min)// если условие выполняется max==b, если нет max=a, как в условии.
min = b;

if(c<min)
min=c;

if(d<min)
min=d;

if(e<min)
min=e;

printf("min=%d", min);


//вариант 2 через тернарный оператор через сравнение трех переменных

//~ int a, b, c, d, e, min, min2;
	//~ scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	

//~ min = a<b ?(a<c?a:c):(b<c?b:c);
//~ min2=min<d? (min<e?min:e):(d<e?d:e);

//~ printf("min2=%d", min2);
	
//вариант 2.1 через тернарный оператор через сравнение четырех переменных	
	//~ int a, b, c, d, e, min, min2;
	//~ scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	

//~ min = (a<b?a:b)<(c<d?c:d)?(a<b?a:b):(c<d?c:d);
//~ min2=min<e?min:e;

//~ printf("min2=%d", min2);
	
	
	return 0;
}

