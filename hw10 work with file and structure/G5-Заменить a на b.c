/*
G5-Заменить a на b

В файле input.txt дана символьная строка не более 1000 символов. 
Необходимо заменить все буквы "а" на буквы "b" и наоборот, 
как заглавные, так и строчные. Результат записать в output.txt.

Формат входных данных:
Строка из маленьких и больших английских букв, 
знаков препинания и пробелов.

Input in input.txt
aabbccddABCD

Формат результата:
Строка из маленьких и больших английских букв, 
знаков препинания и пробелов.

Output
bbaaccddBACD

Решение:

 */



#include <stdio.h>

int main(int argc, char **argv)
{
	FILE*in;
	
	//открываем файл input.txt
	in = fopen("input.txt", "r");
	if (in == NULL){
		perror("input.txt");
		return 1;
	}
	
    // буфер для чтения строки (до 1000 символов + '\0')
    char buffer[1001];
    	
    // считываем всю строку, включая пробелы
    if (fgets(buffer, sizeof(buffer), in) == NULL) {
        printf("Something wrong\n");
        fclose(in);
        return 1;
    }
    fclose(in);

    // вычисляем длину строки до '\0' или до '\n'
    int len = 0;
    while (buffer[len] != '\0' && buffer[len] != '\n') {
        len++;
    }
    buffer[len] = '\0';  // отрезаем возможный '\n'
	
	//создаем массив для новой строки, куда будем добавлять перевернутые символы
	char result [1001];
	
	//проходим по char buffer[1001]
	int i = 0;
	while(buffer[i] != '\0'){
		if(buffer[i] == 'a'){
			result[i] = 'b';
		} else if (buffer[i] ==  'b'){
			result[i] = 'a';
		} else if (buffer[i] ==  'A'){
			result[i] = 'B';
		} else if (buffer[i] ==  'B'){
			result[i] = 'A';
		} else {
			result[i] = buffer[i];
		}
		i++;
	}
	result[i] = '\0';
	
	//записываем результат в output.txt
	FILE*out = fopen("output.txt", "w");
	if(out == NULL){
		perror("output.txt");
		return 1;
	}
	
	fprintf(out, "%s", result);
	fclose(out);
	
	return 0;
}

