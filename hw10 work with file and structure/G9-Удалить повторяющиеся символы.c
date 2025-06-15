/*
G9-Удалить повторяющиеся символы

В файле input.txt строка из меленьких и больших английских букв, 
знаков препинания и пробелов. Требуется удалить из нее повторяющиеся 
символы и все пробелы. Результат записать в файл output.txt.


Формат входных данных:
Строка из меленьких и больших английских букв, 
знаков препинания и пробелов. Размер строки не более 1000 сивмолов.

Input in input.txt
abc cde def

Формат результата:
Строка из меленьких и больших английских букв.

Output
abcdef

Решение:
Прочитать строку из файла (fgets).
Создать массив-флаг (например, размером 256 символов) для отметки, встречался ли уже каждый символ (вы можете использовать тип int или char).
Сделать цикл по всем символам строки:
Если это не пробел и символ ещё не встречался (флаг равен 0), то:
Помечаем символ как встреченный (флаг = 1).
Записываем этот символ в новую строку (или сразу в выходной файл).
Записать результат (строку без повторов и пробелов) в output.txt (fprintf или fputs).
 */


#include <stdio.h>

int main(int argc, char **argv)
{
		//открываем файлы
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	
	if(in==NULL){
		perror("input.txt");
		if(out!=NULL){
			fclose(out);}
		return 1;
	}
	if(out==NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	//читаем строку
	char buf[1001];
	if(fgets(buf, sizeof(buf), in)==NULL){
		printf("file read error");
        fclose(in);
        fclose(out);		
		return 1;
	}
	
	int len = 0;
	while(buf[len] !='\n' && buf[len] != '\0'){
		len++;
	}
	buf[len] = '\0';
	
	//массив для результата
	char result [1001];
	int res_len = 0;
	
	//перебираем строку
	for(int i = 0; i<len; i++){
		if(buf[i] == ' ') continue; // пропуск пробелов. сразу берем следующий i в цикле for
		
		//проверка на повторение символа
		int already = 0;
		for(int j=0; j<res_len; j++){
			if(result[j] == buf[i]){
				already = 1;
				break;
			}
			
		}
		if(already ==0){
			result[res_len] = buf[i];
			res_len++;
		}
	}
	
	//завершаем строку
    result[res_len] = '\0';

    // записываем результат
    fputs(result, out);
    
    fclose(in);
    fclose(out);	
	
	return 0;
}

