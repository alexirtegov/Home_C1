/*
B3-Сумма квадратов

Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.

Формат входных данных:
Два целых числа по модулю не больше 100

Формат результата:
Сумма квадратов от первого введенного числа до второго
 */


#include <stdio.h>

int main(int argc, char **argv)
{
int a,b, sum=0;

if(scanf("%d %d", &a, &b) !=2){
printf("wrong input");
return 0;
}


if(a<=b && a<=100 && b<=100){
for(;a<=b;a++){
sum+=a*a;
}
printf("%d", sum);
}
else
printf("wrong input");


return 0;
}
