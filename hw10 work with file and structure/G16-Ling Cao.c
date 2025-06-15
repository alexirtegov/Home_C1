/*
G16-Ling Cao

В файле input.txt дано предложение. 
Необходимо заменить все имена «Ling» на «Cao» 
и результат записать в файл output.txt.



Формат входных данных:
Строка из английский букв, знаков препинания и пробелов. 
Не более 1000 символов.


Input in input.txt
Ling, Ling, Ling and Ling!!!

Формат результата:
Строка из английский букв, знаков препинания и пробелов.
Output
Cao, Cao, Cao and Cao!!!

Решение:

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
	
	//теперь читаем из buffer[] в result[], когда встерити Ling в buffer в result кладем Cao
	char result [1001];
	int res = 0;
	
	for(int i = 0; buffer[i]!='\0'; i++){
		if(buffer[i] == 'L' && buffer[i+1] == 'i' && buffer[i+2] == 'n' && buffer[i+3] == 'g'){
			result[res ++] = 'C';
			result[res ++] = 'a';
			result[res ++] = 'o';
			i+=3;
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

