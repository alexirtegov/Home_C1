/*
C18-Количество цифр в тексте

Составить логическую функцию, которая определяет, 
что текущий символ это цифра. 
Написать программу считающую количество цифр в тексте. 
int is_digit(char c)

Формат входных данных:
Текст из английских букв и знаков препинания. 
В конце текста символ точка.



Формат результата:
Одно целое число - количество цифр в тексте.
*/


#include <stdio.h>

int is_digit(char c)
{
	if (c>='0' && c<='9'){
		return 1;
	}
	else{
		return 0;
	}
}

int main(int argc, char **argv)
{
	int count = 0;
	int ch;
	
	while ((ch=getchar())!='.' && ch!=EOF){ //пока вызов не точка
		if (is_digit (ch)){ //если вызов return 1 попадаем в счетчик
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}

//вариант 2, где весь расчет производится в функции:
//~ #include <stdio.h>

//~ int is_digit(void)
//~ {
	//~ int count=0;
	//~ int c;
	//~ while ((c=getchar())!='.' && c!=EOF){ //пока вызов не точка
		//~ if (c>='0' && c<='9'){
			//~ count++;
		//~ }
	//~ }
		
	//~ return count;	
		

//~ }

//~ int main(int argc, char **argv)
//~ {
	
	
	//~ printf("%d\n", is_digit());
	
	//~ return 0;
//~ }

