/*
Кратко о сути работы:
Открываем файл "C:\\FILE\\sum.txt" для чтения/записи.
Считаем сумму всех ЦИФР (например, в тексте "abc5de3" найдёт 5 и 3).
В конец файла дописываем эту сумму через пробел.
 */

#include <stdio.h>

int main(void){
	
FILE *f;

    int sum = 0, n;
    
    signed char c;// обязательно signed! иначе зациклится
    
    f = fopen("C:\\FILE\\sum.txt", "r+"); // режим чтение и дозапись
    while ( (c=fgetc(f))!=EOF ) {
        if(c>='0' && c<='9') {
            sum += c-'0';
        }
    }
    fprintf (f, " %d", sum);
    fclose (f);
    return 0;
}
