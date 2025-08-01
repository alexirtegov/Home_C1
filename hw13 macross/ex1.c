/*
 Макрос DEBUGPRINT определен как вызов функции fprintf, 
 которая выводит на стандартный поток ошибок (stderr) 
 строку "debug in %d line\n", где %d заменяется 
 на номер текущей строки в исходном коде 
(это значение предоставляется предопределенным макросом __LINE__).
 
stderr vs stdout:
Вывод в stderr не буферизируется, 
поэтому сообщения появляются немедленно (важно для отладки)
*/


#include <stdio.h>

#define DEBUGPRINT fprintf (stderr, "debug in %d line\n", __LINE__)
// #define — директива препроцессора для создания макроса.
//DEBUGPRINT — имя макроса. При его использовании в коде произойдет подстановка указанного кода.

int main(void)
{
    DEBUGPRINT;		// Эта строка будет заменена на fprintf(stderr, "debug in %d line\n", 8) (если считать, что это 8-я строка)
    
  
  
	DEBUGPRINT;		// Аналогично, но номер строки будет другой
      
      
      
       
       
       
       
       
       
    DEBUGPRINT;        
    return 0;
}
