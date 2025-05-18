/*
C19-Сумма цифр в тексте

Составить функцию, которая преобразует текущий 
символ цифрыв число. 
Написать программу считающую сумму цифр в тексте. 
int digit_to_num(char c)


Формат входных данных:
Текст из английских букв и знаков препинания. 
В конце текста символ точка.



Формат результата:
Целое число - сумма цифр в тексте
*/


//вариант 1
//~ #include <stdio.h>

//~ int digit_to_num(char c)
//~ {
	//~ if (c>='0' && c<='9'){
		//~ return (c-'0');
	//~ }
	//~ else{
		//~ return 0;
	//~ }
//~ }

//~ int main(int argc, char **argv)
//~ {
	//~ int sum = 0;
	//~ int ch;
	
	//~ while ((ch=getchar())!='.' && ch!=EOF){ //пока вызов не точка
		
			//~ sum+=digit_to_num(ch);
		//~ }
	
	
	//~ printf("%d\n", sum);
	
	//~ return 0;
//~ }

//вариант 2


#include <stdio.h>

int digit_to_num(void)
{
	int sum = 0;
	int ch;
	
	while ((ch=getchar())!='.' && ch!=EOF){ 
	
	if (ch>='0' && ch<='9'){
		sum+=(ch-'0');
		
		}
}
return sum;
}

int main(int argc, char **argv)
{
	
	printf("%d\n", digit_to_num());
	
	return 0;
}
