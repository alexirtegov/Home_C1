/*
    Ввести пять чисел и найти наибольшее из них.
    
    Формат входных данных:
    Пять целых чисел разделенных пробелом
    
    Формат результата:
    Одно целое число

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//вариант 1
	
	//~ int a, b, c, d, e, max;
	//~ scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	//~ max = a;
	


//~ if(b>max)// если условие выполняется max==b, если нет max=a, как в условии.
//~ max = b;

//~ if(c>max)
//~ max=c;

//~ if(d>max)
//~ max=d;

//~ if(e>max)
//~ max=e;

//~ printf("max=%d", max);


//вариант 2 через тернарный оператор через сравнение трех переменных

//~ int a, b, c, d, e, max, max2;
	//~ scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	//~ max = a;
	

//~ max = a>b ?(a>c?a:c):(b>c?b:c);
//~ max2=max>d? (max>e?max:e):(d>e?d:e);

//~ printf("max2=%d", max2);
	
//вариант 2.1 через тернарный оператор через сравнение четырех переменных	
	int a, b, c, d, e, max, max2;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	max = a;
	

max = (a>b?a:b)>(c>d?c:d)?(a>b?a:b):(c>d?c:d);
max2=max>e?max:e;

printf("max2=%d", max2);
	
	
	return 0;
}



