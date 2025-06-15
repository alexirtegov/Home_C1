/*
G1-Три раза

В файле input.txt дана строка. Вывести ее в файл output.txt 
три раза через запятую и показать количество символов в ней.


Формат входных данных:
Строка из английских букв и пробелов. Не более 100 символов. 
В конце могут быть незначащие переносы строк.

Input in input.txt
aab

Формат результата:
Исходная строка 3 раза подряд, через запятую пробел и количество 
символов в ней.

Output
aab, aab, aab 3

Решение:
Ввод массива
*/

//~ #include <stdio.h> 	
//~ #define SIZE 101


	
//~ int main() {
    //~ FILE *file1;
    //~ FILE *file2;

    //~ // сюда добавляем недостающие объявления
    //~ char buffer[SIZE];
    //~ int  count = 0;
    //~ int  c;
     
    // 1. Открываем файл для записи "input.txt"
    //~ file1 = fopen("input.txt", "w");
    //~ if (file1 == NULL) {
        //~ printf("Failed to open file for writing\n");
        //~ return 1;
    //~ }
    //~ // 2. Пишем строку "aab" в файл "input.txt"
    //~ fprintf(file1, "aab");
    //~ // 3. Закрываем файл после записи
    //~ fclose(file1);
    
    //~ // 4. Открываем файл "input.txt" для чтения
   
    //~ //1. Открываем файл "input.txt" на чтение
    //~ file1 = fopen("input.txt", "r");
    //~ if (file1 == NULL) {
        //~ printf("Failed to open file for reading\n");
        //~ return 1;
    //~ }

    //~ //2. Читаем символы из файла input.txt
    //~ while ((c = fgetc(file1)) != EOF && count < SIZE - 1) {
        //~ buffer[count++] = (char)c;
    //~ }
    //~ buffer[count] = '\0';

	
    //~ //7. Закрываем файл "input.txt" после чтения
    //~ fclose(file1);
    
     //~ // —––––––––––––––––––––––––––––––––––––––––––––––
    //~ // Добавляем всего два действия:
    //~ // если в конце buffer стоит '\n', заменяем его на '\0' и уменьшаем count
    //~ if (count > 0 && buffer[count-1] == '\n') {
        //~ buffer[count-1] = '\0';
        //~ count--;
    //~ }
    //~ // —––––––––––––––––––––––––––––––––––––––––––––––
    
    //~ //8. Открываем файл для записи "output.txt" 
    //~ file2 = fopen("output.txt", "w");
     //~ if (file2 == NULL) {
        //~ printf("Failed to open file for writing\n");
        //~ return 1;
    //~ }   
    
    //~ //9. Записываем в "output.txt" содержимое buffer три раза и затем count
    //~ //   Формат: <buffer>, <buffer>, <buffer> <count> 
    //~ fprintf(file2, "%s, %s, %s %d", buffer, buffer, buffer, count);
    
    //~ //9. Закрываем файл "output.txt"  после записи
    //~ fclose(file2);
    
    //~ // 10. Открываем файл "output.txt"  для чтения
    //~ file2 = fopen("output.txt", "r");
    //~ if (file2 == NULL) {
        //~ printf("Failed to open file for reading\n");
        //~ return 1;
    //~ }
    
    //~ // 11. Читаем строку из "output.txt"
    //~ char buffer2[SIZE];
    //~ if (fgets(buffer2, SIZE, file2)== NULL){
		//~ printf("Failed to open file for reading\n");
        //~ fclose(file2);
        //~ return 1;
    //~ }
    
    //~ //12. Закрываем файл "output.txt"
    //~ fclose(file2);
    
    //~ //13. выводим "output.txt" и счетчик count
    //~ printf("%s\n", buffer2);

    //~ return 0;
//~ }

//вариант 2
#include <stdio.h>
#define SIZE 101

int main(void) {
    char buffer[SIZE];
    int  count = 0;

    // Открываем существующий input.txt для чтения
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Failed to open file for reading\n");
        return 1;
    }

    // Читаем строку
    /*Функция fgets(buffer, SIZE, in) читает из файла до SIZE−1 символов (либо до символа ‘\n’, 
     либо до конца файла) и сразу же записывает прочитанные байты в ваш массив buffer. 
     При этом она автоматически дописывает терминатор ‘\0’ в конец строки. 
     Если чтение прошло успешно, то buffer уже содержит вашу строку, 
     и вы можете дальше с ней работать (обрезать ‘\n’, подсчитать длину и т. д.). 
     Закрытие файла на это никак не повлияет – данные в локальном массиве останутся.
     */
    
    if (fgets(buffer, SIZE, in)==NULL) {
        fclose(in);
        return 1;
    }
    fclose(in);


	// Обрезаем возможный '\n' и считаем count */
	while (buffer[count]!='\0' && buffer[count] != '\n'){
		count ++;
	}
	if(buffer[count] =='\n'){
		buffer[count] = '\0';
	}
	
	
    // Открываем output.txt для записи
    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Failed to open file for reading\n");
        return 1;
    }
    
    // Пишем ровно одну строку без лишних '\n'
    fprintf(out, "%s, %s, %s %d", buffer, buffer, buffer, count);
    
    //закрываем
    fclose(out);
    
    

   //открываем output.txt для чтения
    out = fopen("output.txt", "r");
        if (out == NULL) {
        printf("Failed to open file for reading\n");
        return 1;
    }
    
    char buffer2[SIZE];
     if (fgets(buffer2, SIZE, out)==NULL) {
        fclose(in);
        return 1;
    }
  
    //закрываем
    fclose(out);   
    
    printf("%s\n", buffer2);


    return 0;
}
