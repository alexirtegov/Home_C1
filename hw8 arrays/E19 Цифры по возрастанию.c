/*
E19-Цифры по возрастанию

Вывести в порядке следования цифры, 
входящие в десятичную запись натурального числа N.


Формат входных данных:
Одно натуральное число N
Input
54412

Формат результата:
Цифры через пробел
Output
5 4 4 1 2
*/



#include <stdio.h>

int How_many_digits_in_number(int number)
{
	if(number == 0) return 1;
	
	int N=number<0 ? -number : number;
	int count=0;
	while(N>0){
		N=N/10;
		count++;
	}
	return count;
}
//Вариант 1 
//~ void Transfer(int number, int count)//number = 54412, count=5
//~ {
	//~ int p10 = 1;
    //~ for (int i = 1; i < count; i++) { //p10=10000
        //~ p10 *= 10;
    //~ }
	//~ printf("%d\n", p10); //проверка
	
//~ for (int i = 0; i < count; i++) {// 54412
        //~ int digit = number / p10;    // 1) 54412 / 10000=5 2)4412/1000=4
        //~ printf("%d ", digit);//1) печать 5 2)4
        //~ number = number%p10;// 1)54412%10000 = 4412
        //~ p10 /= 10; //1)10000/10 = 1000
    //~ }
//~ }

//вариант 2

void Transfer(int number, int count)
{
    for (; count > 0; count--) {//54412
        int N = number;
        int n = N % 10;// это нужно для последней цифры  

  
        for (int i = count - 1; i > 0; i--) {
            N /= 10;
            n = N % 10;
        }

        printf("%d ", n);
    }
}

int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	
	int count = How_many_digits_in_number(number);
	
	Transfer(number, count);
	
	//~ printf("%d", count);
	
	return 0;
}

