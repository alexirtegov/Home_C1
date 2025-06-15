/*
G11-Заканчивается на a


В файле input.txt дано предложение. Необходимо определить, 
сколько слов заканчиваются на букву 'а'. Ответ записать в файл 
output.txt.



Формат входных данных:
Строка из английских букв и пробелов не более 1000 символов.

Input in input.txt
Mama mila ramu

Формат результата:
Одно целое число
Output
2

Решение (можно брать):
Посмотреть на каждый пробел и конец строки: 
если перед ним стоит буква 'a', увеличить ответ.

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	
	if(in == NULL){ //если отсутствие данных
		perror("input.txt");
		if(out != NULL){
			fclose(out);
		}
		return 1;
	}
	
	if(out == NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	//читаем input.txt с помощью fgets в buffer[1001]
	char buffer[1001];
	
	if(fgets(&buffer[0], sizeof(buffer), in) == NULL){
		printf("file read error");
		fclose(in);
		fclose(out);
		return 1;
	}
	
	//теперь у нас есть заполннеый буфер проверяем есть ли 
	//перед пробелом ' ' или концом строки '/n' символ 'a'
	
	int a = 0; // счтечик для символа 'a'
	for(int i = 1; buffer[i]!='\0'; i++){ //начинаем с i=1, чтобы при [i-1] не выйти за границу
		if(buffer[i] == ' ' || buffer[i] =='\n'){
			if(buffer[i-1] == 'a'){
				a++;
			}
		}
	}
	
	fprintf(out, "%d", a);
	
		fclose(in);
		fclose(out);
	
	
	return 0;
}

