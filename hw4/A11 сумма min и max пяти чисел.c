/*Задание A11  Сумма максимума и минимума
    Напечатать сумму максимума и минимума.
    
    Формат входных данных:
    Пять целых чисел через пробел
    
    Формат результата:
    Одно целое число - сумма максимума и минимума
 */

#include <stdio.h>

int main(void)
{
int a, b, c, d, e, max, min, res;
scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
//находим максимум использую тернарный оператор
max= (a>b?a:b)>(c>d?c:d)?(a>b?a:b):(c>d?c:d);
max=max>e?max:e;

//находим минимум
min=a;
if(b<min)
min=b;
if(c<min)
min=c;
if(d<min)
min=d;
if(e<min)
min=e;

//находим сумму

res=max+min;
printf("res=%d", res);

return 0; 
}
