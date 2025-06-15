/*
G15-Cao Ling

В файле input.txt дано предложение. 
Необходимо заменить все имена «Cao» на «Ling» и 
записать результат в файл output.txt.


Формат входных данных:
Строка из английский букв, знаков препинания и пробелов. 
Не более 1000 символов.


Input in input.txt
Cao, Cao, Cao and Cao!!!

Формат результата:
Строка из английский букв, знаков препинания и пробелов.
Output
Ling, Ling, Ling and Ling!!!

Решение:
Открыть файл для чтения с помощью функции fopen("input.txt", "r").

Считать всю строку в массив символов (например, buffer[1001]) 
с помощью fgets.

Подготовить второй массив (например, result[2001]), в который будешь 
записывать результат замены.

Сделать цикл по всем символам строки:
Если ты встретил подряд три буквы C, a, o и знаешь, 
что перед этим либо пробел, либо начало строки, а после
либо пробел, запятая, точка, восклицательный, 
либо конец строки — значит, это слово "Cao".
Вместо этих трёх символов в результат записать "Ling".
И увеличить индекс на три для исходного массива и на четыре 
для результата.
В других случаях — просто копировать символы из исходного 
массива в результат.

После окончания цикла записать результат в файл output.txt с помощью fprintf или fputs.

Закрыть оба файла с помощью fclose.

 */



#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	if(in==NULL){
		perror("input.txt");
		if(out!= NULL){
			fclose(out);
		}
		return 1;
	}
	if(out==NULL){
		perror("output.txt");
		fclose(in);
		return 1;	
	}
	
	//читаем строку из файла в массива
	char buffer [1001];
	if(fgets(buffer, sizeof(buffer), in) ==NULL ){
		fclose(in);	
		fclose(out);
		printf("error read file");
		return 1;
	}
	
	//теперь читаем из buffer[] в result[], когда встерити Cao в buffer в result кладем Ling
	char result [1001];
	int res = 0;
	
	for(int i = 0; buffer[i]!='\0'; i++){
		
		if(buffer[i] == 'C' && buffer[i+1] == 'a' && buffer [i+2] == 'o'){
			result[res++] = 'L';
			result[res++] = 'i';
			result[res++] = 'n';
			result[res++] = 'g';
			i+=2;
			continue; 
			
		} else {
		result[res++] = buffer[i];
		}
	}
	result[res] = '\0';
	fprintf(out, "%s", result);
    fclose(in);
    fclose(out);

	
	return 0;
}

