/*
G6-Проверка на палиндром

В файле input.txt символьная строка не более 1000 символов. 
Необходимо проверить, является ли она палиндромом 
(палиндром читается одинаково в обоих направлениях). 
Реализовать логическую функцию is_palindrom(str) и 
записать ответ в файл output.txt.


Формат входных данных:
Строка из заглавных английских букв

Input in input.txt
KAZAK

Формат результата:
YES или NO

Output
YES

Решение:
Открыть файлы
– Для чтения: FILE *in = fopen("input.txt", "r");
– Для записи: FILE *out = fopen("output.txt", "w");
Считать строку
– Использовать fgets(buffer, sizeof buffer, in); чтобы захватить всю строку (до 1000 символов).
– Удалить «хвостовой» '\n' (если он есть), пройдя по buffer до '\0' или '\n' и заменив его на '\0'.
Написать логическую функцию is_palindrom
– Сигнатура: int is_palindrom(const char *s); (возвращает 1, если палиндром, 0 иначе).
– Внутри держать два индекса или два указателя:
• i = 0;
• j = strlen(s) - 1;
– Цикл while (i < j):
• Сравнить s[i] с s[j].
• Если они не равны → вернуть 0.
• Иначе i++, j--.
– После цикла вернуть 1.
В main вызвать is_palindrom(buffer).
– Если вернуло 1 → записать в output.txt строку "YES".
– Иначе → "NO".
Закрыть файлы fclose(in); fclose(out);
 */



#include <stdio.h>

int is_palindrom(char buffer[], int length){
	for(int i =0, j = length - 1; i<j;){
		if(buffer[i] == buffer[j]){
			i++;
			j--;
		} else {
			return 0;
		}

	}
	return 1;
}

int main(int argc, char **argv)
{
	//открываем срзу оба файла
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	if(in == NULL ){
		perror("input.txt");
		if(out!=NULL){
			fclose(out);
		}
		return 1;
	}
	if (out == NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	//считаем строку из input.txt через fgets и кладем ее в массив buffer
	
	char buffer [1001];
	if (fgets(&buffer[0], sizeof(buffer), in)==NULL){
		printf("file read error");
		return 1;
	}
	
	//обрежем перевод строки '\n' и заменем его на '\0'
	int length=0;
	while (buffer[length]!= '\n' && buffer[length]!= '\0'){
		length ++;
	}
	buffer[length] = '\0';
	
	//запишем в файл output.txt результат через обработку в функции
	fprintf (out, "%s", is_palindrom(&buffer[0], length) ==1 ? "YES" : "NO");
	fclose(in);
	fclose(out);
	
	return 0;
}

