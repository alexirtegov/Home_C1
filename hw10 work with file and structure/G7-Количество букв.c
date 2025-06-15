/*
G7-Количество букв

В файле input.txt считать символьную строку, не более 10 000 символов. 
Посчитать количество строчных (маленьких) и прописных (больших) букв 
в введенной строке. Учитывать только английские буквы. 
Результат записать в файл output.txt.

Формат входных данных:
Строка состоящая из английских букв, цифр, 
пробелов и знаков препинания.

Input in input.txt
HELLO WORLD

Формат результата:
Два целых числа. 
Количество строчных букв и количество заглавных букв.

Output
0 10

Решение:

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//открываем наши файлы input.txt - для чтения и output.txt. - для записи
	FILE*in = fopen("input.txt", "r" );
	FILE*out = fopen ("output.txt", "w");
	
	if(in == NULL){
		perror("input.txt");
		if(out!=NULL){
			fclose(out);
		}
		return 1;
	}
	
	if(out==NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	//читаем строку из input.txt в массив через функцию fgets
	char buffer[10001];
	if(fgets(&buffer[0], sizeof(buffer), in)==NULL){
		printf("file read error");
		return 1;
	}
	//заменяем '\n' на '\0';
	int len = 0;
	while(buffer[len]!='\n' && buffer[len]!='\0'){
		len++;
	}
	buffer[len] = '\0';
	
	//считаем английские буквы в массиве buffer[len], если английская то сморим большая или маленькая
	int count_a = 0;  //счетчик для маленький английских букв
	int count_A = 0;  //счетчик для больших английских букв
	
	for(int i = 0; i<len; i++){
		if(buffer[i]>='A' && buffer[i]<='Z'){
			count_A++;
		}
		else if(buffer[i]>='a' && buffer[i]<='z'){
			count_a++;
		} 
	}
	
	//запишем данные со счетчиков в output.txt
	fprintf(out, "%d %d",count_a, count_A);
	fclose(in);
	fclose(out);

	
	return 0;

}

