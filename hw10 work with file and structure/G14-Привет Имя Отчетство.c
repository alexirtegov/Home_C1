/*
 G14-Привет Имя Отчетство

В файле input.txt в одной строке фамилию, имя и отчество. 
Сформировать файл приветствие output.txt, 
где останутся имя и фамилия


Формат входных данных:
Строка состоящая из английских букв и пробелов не более 100 символов. 
Формат: Фамилия Имя Отчество


Input in input.txt
Pupkin Vasiliy Ivanovich

Формат результата:
Строка состоящая из английских букв и пробелов
Output
Hello, Vasiliy Pupkin!

Решение (средне):
Считать строку из файла input.txt с помощью функции fscanf или fgets.
Найти позиции первого и второго пробела в считанной строке 
(пройти по массиву char посимвольно циклом).
Выделить нужные части: фамилию и имя — фамилия идёт от начала строки 
до первого пробела, имя — между первым и вторым пробелом.
Записать приветствие в output.txt с помощью функции fprintf: 
"Hello, {Имя} {Фамилия}!".

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	
	if(in == NULL){
		perror("input.txt");
		if(out!=NULL){
			fclose(out);
		}
		return 1;
	}
	
	if(out == NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}
	
	
	//читаем input.txt через fgets в buffer[1001]
	char buffer [1001];
	if(fgets(&buffer[0], sizeof(buffer), in) == NULL){
		printf("file read error");
		fclose(in);
		fclose(out);
		return 1;
	}
	
	//теперь наша строка в buffer[1001]
	char fam [101]; // сюда будем записывать фамилию
	int f = 0;
	
	char name [101];
	int n = 0;
	
	int i = 0;
	// Копируем фамилию (до первого пробела)
	while (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\n') {
		fam[f++] = buffer[i++];
	}
	fam[f] = '\0';

	// Пропускаем пробел(ы)
	while (buffer[i] == ' ') i++;

	// Копируем имя (до пробела или конца строки/строки перевода)
	while (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\n') {
		name[n++] = buffer[i++];
	}
	name[n] = '\0';
	
	fprintf(out, "Hello, %s %s!", name, fam);

		fclose(in);
		fclose(out);
		
	
	return 0;
}

