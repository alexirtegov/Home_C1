/*
B11-Перевернуть число
Ввести целое число и «перевернуть» его, 
так чтобы первая цифра стала последней и т.д.

Формат входных данных:
Целое неотрицательное число

Формат результата:
Целое не отрицательное число наоборот
*/


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	if(scanf("%d", &number)!=1){
		printf("wrong input\n");
		return 0;
	}
	
	if (number == 0) {
        printf("0\n");
        return 0;
	}
        
/*
возьмем в качестве примера число 125 обратное число будет 521
число 521 может быть получено 1*1+2*10+5*100 = 521

Решение:
1) сначала возьмем переменную вне цикла counter =0; в этой переменной мы будем считать наше обратное число
2) создадим цикл где условием будет number>0
3) внутри цикла создадим временную переменную в которую будем заносить последнюю цифру int current;
4) current= number%10 = 125%10  current=5
5) для того чтобы сдвинуть 5 влево и освободить место для 2 мы должны произвести умножение на 10
   для это возьмем нашу переменную в которую будем записывать резульатат counter=counter*10+current;
   counter=0*10+5  counter=5
6) обрежем правую цифру number=number/10; number=125/10   number=12
7) действия 4-6 это цикл for(int current;number>0;)

4)current= number%10 = 12%10  current=2
5)counter=counter*10+current;  counter=5*10+2  counter=52
6)number=number/10; number=12/10   number=1

4)current= number%10 = 1%10  current=1
5)counter=counter*10+current;  counter=52*10+1  counter=521
6)number=number/10; number=1/10   number=0 Цикла нарушен и закончен
*/
    int counter =0;
    for(int current; number>0;){
		current= number%10;
		counter=counter*10+current;
		number=number/10;
	}
	printf("%d", counter); 


	
	
	return 0;
}

