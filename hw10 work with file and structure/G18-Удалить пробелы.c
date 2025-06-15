/*
G18-Удалить пробелы

В файле input.txt необходимо удалить все лишние пробелы 
(в начале предложения и сдвоенные пробелы). 
Для решения задачи разработать функцию. 
Результат записать в output.txt.

Формат входных данных:
Строка из английских букв, пробелов и знаков препинания. 
Не более 1000 символов.


Input in input.txt
    Hello     world!

Формат результата:
Строка из английских букв, пробелов и знаков препинания.
Output
Hello world!

Решение:
Всё делается просто — читаешь строку, проходишь её по символам, 
переписываешь во второй массив, не давая подряд идти двум пробелам, 
а начальные вообще пропускаешь. 
 */


#include <stdio.h>

void remove_extra_spaces(char buffer[], char result[])
{
	int i = 0; //положение места чтения в buffer[]
	int j = 0; //положение места куда записываем строку без пробелов
	
	while (buffer[i] == ' '){ //здесь мы установим i  в положение не первого пробела
		i++;
	}
	
	int space_flag =0; 			//устанавливаем флаг пробела
	for(; buffer[i]!='\0' && buffer[i]!='\n';i++){
		if(buffer[i] != ' '){
			result [j++] = buffer[i];
			space_flag = 0;  	//положение флага 0 - то есть пробела нет
	} else {					//встретили пробел
		if(space_flag == 0){	// если пробела не было ставим
			result [j++] = ' ';
			space_flag = 1; // раз сюда попали значит пробел поставили
		}
	}

	}
	 // Завершить строку
    result[j] = '\0';	
}

int main(int argc, char **argv)
{
	FILE*in = fopen("input.txt", "r");
	FILE*out = fopen("output.txt", "w");
	
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
	
	char buffer[1001]; //записали строку из файла в буфер
	if(fgets(buffer, sizeof(buffer), in)==NULL){
		printf("Error read file");
		fclose(out);
		fclose(in);
		return 1;
	}
	
	char result[1001];
	
	remove_extra_spaces(buffer, result);
	
	fprintf(out, "%s", result);
	fclose(out);
	fclose(in);
	
	return 0;
}

