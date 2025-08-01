/*
F16-Черное или белое

Известно, что шахматная доска имеет размерность 8х8 и состоит из клеток 2х цветов, 
например, черного и белого (см. рисунок). 
Каждая клетка имеет координату, состоящую из буквы и цифры. 
Горизонтальное расположение клетки определяется буквой от A до H, 
а вертикальное – цифрой от 1 до 8. 
Заметим, что клетка с координатой А1 имеет черный цвет. 
Требуется по заданной координате определить цвет клетки.



Формат входных данных:
В единственной строке входного файла записана координата клетки на шахматной доске: 
всего два символа – буква и цифра (без пробелов).
Input
C3

Формат результата:
В выходной файл нужно вывести «WHITE», 
если указанная клетка имеет белый цвет и «BLACK», если она черная.
Output
BLACK

Решение:
У шахматной доски цвета клеток идут в шахматном порядке. 
Клетка A1 черная, рядом с ней по горизонтали и вертикали всегда противоположный цвет.

Каждой букве от A до H соответствует номер столбца (A — 1, B — 2, …, H — 8).
Каждой цифре от 1 до 8 — номер строки (просто сама цифра).

В шахматном порядке правило: клетка черная, если сумма координат (номер столбца + номер строки) — четное число.
Иначе — белая.

Иначе говоря: если (номер_буквы + номер_цифры) четно — цвет “BLACK”.
Если нечетно — цвет “WHITE”.

Пример:

C3: C = 3, 3 = 3, сумма 6, четно — значит “BLACK”.
B1: B = 2, 1 = 1, сумма 3, нечетно — “WHITE”.
H8: H = 8, 8 = 8, сумма 16, четно — “BLACK”.

Вывод: задача сводится к переводу буквы в число (A=1, ... H=8), сложении с цифрой, определению чётности суммы и выводу цвета.
*/

//через двухмерный массив вариант 1

//~ #include <stdio.h>
//~ #define SIZE 8 //в шахматной доске 8 столбцов и 8 строк

//~ int main() {
    //~ char color[SIZE][SIZE]; // Двумерный массив для хранения символа 8 на 8

    //~ // Заполняем двумерный массив: 'B' — чёрная клетка, 'W' — белая
    //~ for (int row = 0; row < SIZE; row++) {
        //~ for (int col = 0; col < SIZE; col++) {
            //~ if ((row + col) % 2 == 0) { //проверка на четность все четные черные 
                //~ color[row][col] = 'B'; // BLACK например С3 - это color[2][2]
            //~ } else {
                //~ color[row][col] = 'W'; // WHITE
            //~ }
        //~ }
    //~ }

    //~ // Ввод координаты: например, В3 (латиницей, большие буквы)
    //~ char input[3]; // в массив помещаются символ буквы, цифры и 3-я ячейка памяти для '/0' 
    //~ //input[0] -всегда буква, input[1] - всегда цифра
    //~ printf("Enter the coordinate (eg., C3): ");
    //~ scanf("%2s", input); //

    //~ int col = input[0] - 'A'; // Преобразуем букву в номер столбца Для ввода С3 получаем 'C'-'A' = 67-65 = 2
    //~ int row = input[1] - '1'; // Преобразуем цифру в номер строкиД ля ввода С3 получаем '3'-'1' = 51-49 = 2

    //~ if (col < 0 || col >= SIZE || row < 0 || row >= SIZE) {
        //~ printf("Wrong coordinate\n");
        //~ return 1;
    //~ }

    //~ // Выводим полный цвет клетки
    //~ if (color[row][col] == 'B') { // для с3 получаем color[0][0]  == 'B' В цикле мы поместили туда 'B', поскольку (2 + 2) % 2 == 0
        //~ printf("BLACK\n");
    //~ } else {
        //~ printf("WHITE\n");
    //~ }

    //~ return 0;
//~ }



//через двухмерный массив вариант 2 сразу строка

#include <stdio.h>
#define SIZE 8 //в шахматной доске 8 столбцов и 8 строк

int main()
{
	char*color[SIZE][SIZE]; // это массив указателей на строку
	for(int row =0; row<SIZE; row++){
		for(int col =0; col<SIZE; col++){
			if((col+row)%2 == 0){
				color[row][col] = "BLACK"; // если ==0 совпадает то указатель в массиве будет указывать на "Черный"
			} else {
				color[row][col] = "WHITE";
			}
		}
	}
	
	printf("Please enter the cell coordinates (for example, C3): ");
	char input[3]; // для ввода буквы, цифры и одна ячейка памяти для '\0'
	// например, пользователь введет C3 => input[0]='C', input[1]='3', input[2]='\0'

	scanf("%s", input); // для ввода "C3" получаем {'C', '3', '\0'}
	int row =input[1]-'1';
	int col =input[0]-'A';
	
	if(row<0 || row>SIZE || col<0 || col>SIZE){
		printf("Error input");
		return 0;
	}
	
	//выводим результат
	printf("%s", color[row][col]);
	
}



//вариант 2 без массива

//~ #include <stdio.h>

//~ int main(int argc, char **argv)
//~ {
	//~ char column_character; // переменная для букв
	//~ int row_number;
	
	//~ printf("Please enter the cell coordinates (for example, C3): ");
	//~ scanf("%c%d", &column_character, &row_number);
	
	//~ //переводим символ столбца в цифру столбца
	//~ int column_number = (column_character - 'A') +1; // для ввода 'C' имеем 'C' - 'A' = 67 - 65 = 2 + 1 =3
	
	//~ //проверяем условие четности
	//~ if((column_number + row_number)%2 ==0){
		//~ printf("BLACK \n");
	//~ } else {
		//~ printf("WHITE\n");
	//~ }
	
	//~ return 0;
//~ }

