/*
Задание A18       Above, less, equal

    Ввести два числа. Если первое число больше второго, то программа печатает слово Above.  
    Если первое число меньше второго, то программа печатает слово Less.
    А если числа равны, программа напечатает сообщение Equal.
    
    Формат входных данных:
    Два целых числа
    
    Формат результата:
    Одно единственное слово: Above, Less, Equal

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	//вариант 1 - через если
	//~ if (a>b)
	//~ printf("Above");
	
	//~ if (a<b)
	//~ printf("Less");
	
	//~ if (a==b)
	//~ printf("Equal");
	
	//вариант 2 через тернарный
	printf("%s", (a>b)?"Above":
	             (a<b)?"Less":"Equal");
	             
	
	return 0;
}

