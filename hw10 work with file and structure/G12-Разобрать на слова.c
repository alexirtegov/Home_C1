/*
G12-Разобрать на слова


В файле input.txt дано предложение требуется разобрать 
его на отдельные слова. Напечатать каждое слово на 
отдельной строке в файл output.txt.


Формат входных данных:
Одна строка из английских букв и пробелов не более 1000 символов.

Input in input.txt
Mama mila ramu

Формат результата:
Каждое слово на отдельной строке
Output
Mama
mila
ramu

Решение (можно брать):
проход посимвольно по строке и разделение на слова руками, 
записывая каждое слово отдельно.
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
	char current [1001]; // сюда будем записывать слова
	int cur = 0;
	
	for(int i = 0; buffer[i]!='\0'; i++){
		if(buffer[i]!= ' ' && buffer[i] != '\n'){
			current[cur] = buffer[i];
			cur++;
		} else {
			if (cur>0){
				current[cur] = '\0';
				fprintf(out, "%s\n", current);
				cur = 0;
			}
		}
	}
	
	if (cur>0){
        current[cur] = '\0';
        fprintf(out, "%s\n", current);
    }
		fclose(in);
		fclose(out);
		
	
	return 0;
}

