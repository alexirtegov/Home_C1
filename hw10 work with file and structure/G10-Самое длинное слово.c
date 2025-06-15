/*
G10-Самое длинное слово

В файле input.txt дана строка слов, разделенных пробелами. 
Найти самое длинное слово и вывести его в файл output.txt. 
Случай, когда самых длинных слов может быть несколько, не обрабатывать.


Формат входных данных:
Строка из английских букв и пробелов. Не более 1000 символов.

Input in input.txt
Hello beautiful world

Формат результата:
Одно слово из английских букв.
Output
beautiful

Решение:
Читаешь строку символ за символом, начиная с начала (например, через fgetc из файла).
Когда видишь букву (не пробел) — добавляешь её в текущий временный массив (назовём его "текущее слово").
Когда наткнулся на пробел или на конец строки:
Проверяешь, не пустое ли текущее слово.
Сравниваешь длину текущего слова с максимальной найденной до сих пор.
Если текущее слово длиннее — копируешь его в отдельный массив ("самое длинное слово").
Обнуляешь длину текущего слова (чтобы начать собирать следующее).
В конце файла повторяешь тот же шаг, если последнее слово не закончилось пробелом.
Записываешь самое длинное слово в файл output.txt через fprintf.
 */


//вариант 1 через fgetc
//~ #include <stdio.h>

//~ int main(int argc, char **argv)
//~ {
	//~ FILE*in = fopen("input.txt", "r");
	//~ FILE*out = fopen("output.txt", "w");
	
	//~ if(in == NULL){
		//~ perror("input.txt");
		//~ if(out!=NULL){
			//~ fclose(out);
		//~ }
		//~ return 1;
	//~ }
	
	//~ if(out == NULL){
		//~ perror("output.txt");
		//~ fclose(in);
		//~ return 1;
	//~ }
	
	//~ //читаем содержимое файла и записываем по символам в массив  current [1001] пока не встретим пробел или перенос строки
	//~ char ch;
	//~ char current [1001]; //временный массив, сюда набираем очередное слово посимвольно.
	//~ int cur_len = 0; //длина текущего слова.
	//~ char longest[1001];   // здесь будет самое длинное слово из всех.
	//~ int max_len = 0; // длина самого длинного слова.

    //~ while ((ch = fgetc(in)) != EOF) { 		//Пока не достигнут конец файла (EOF), берём следующий символ и кладём его в ch.
        //~ if (ch != ' ' && ch != '\n') {	 	//Если ch не пробел и не перевод строки (\n) — это буква слова из нашей строки
            //~ current[cur_len] = ch; 			//формируем массив слова
            //~ cur_len++;
        //~ } else {        					//сюда попадаем когда встретили пробел или перевод строки
            //~ if (cur_len > 0) {
                //~ current[cur_len] = '\0'; // конец строки
                //~ if (cur_len > max_len) {
                    //~ max_len = cur_len;
                    //~ int i;
                    //~ for (i = 0; i <= cur_len; i++)
                        //~ longest[i] = current[i]; // копируем с нулём-терминатором
                //~ }
                //~ cur_len = 0; // начинаем собирать следующее слово
            //~ }
        //~ }
    //~ }
    //~ // Вдруг последнее слово не завершилось пробелом
    //~ if (cur_len > 0) {
        //~ current[cur_len] = '\0';
        //~ if (cur_len > max_len) {
            //~ max_len = cur_len;
            //~ int i;
            //~ for (i = 0; i <= cur_len; i++)
                //~ longest[i] = current[i];
        //~ }
    //~ }
    
    //~ fprintf(out, "%s", longest);
    
    //~ fclose(in);
    //~ fclose(out);	
	
	//~ return 0;
//~ }



//вариант 2 через fgets


#include <stdio.h>

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
	
//читаем всю строку и записываем в массив buffer[1001];
	char buffer [1001];
	if(fgets(&buffer[0], sizeof(buffer), in) == NULL){
		printf("file read error");
        fclose(in);
        fclose(out);		
		return 1;
	}
	
// теперь строку будем разбивать на слова по прнципу до ' ' или '\n'
	char current[1001];
	int cur_len = 0;
	char longest [1001];
	int max_len = 0;
	
	for (int i = 0; buffer[i] != '\0'; i++){
		if(buffer[i] != ' ' && buffer[i] != '\n'){
			current[cur_len] = buffer[i];
			cur_len ++;
		} else {
			if(cur_len>0){
				current[cur_len] = '\0';
			}
			if(cur_len>max_len){
				max_len= cur_len;
				for(int j = 0; j<= max_len; j++){
					longest[j]=current[j];
				}
				
			}
			cur_len=0;
		}
	}

     if (cur_len > 0) {
        current[cur_len] = '\0';
        if (cur_len > max_len) {

            for (int j = 0; j <= cur_len; j++)
                longest[j] = current[j];
        }
    }
    
    
 
	fprintf(out, "%s", longest);
 
    fclose(in);
    fclose(out);	
	
	return 0;
}
