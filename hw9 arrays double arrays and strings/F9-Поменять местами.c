/*
F9-Поменять местами

Составить только функцию которая в массиве находит максимальный 
из отрицательных элементов и меняет его местами с последним 
элементом массива. Гарантируется, что в массиве только один 
такой элемент или же такой элемент отсутствует. 
Если отрицательных элементов нет - массив не менять.
Прототип функции: void swap_negmax_last(int size, int a[])

Формат входных данных:
Функция принимает на вход размер массива и указатель на начало массива. 
Массив состоит из целых чисел.

Input
1 -2 -3 -4 5 6 7 8 9 10

Формат результата:
Одно целое число

Output
1 10 -3 -4 5 6 7 8 9 -2
Решение:
*/

//мой вариант дорабоать

	#include <stdio.h>
	#define SIZE 10

	int Input_array(int array[], int N)
{
	int number_of_digit =0;
	for(int i =0; i<N; i++){
		if(scanf("%d", &array[i])!=1){
		printf("Error");
		return 0;
		}

	number_of_digit ++; //считаем количество заполненных ячеек памяти в массиве
	}
	return number_of_digit;
}

void swap_negmax_last(int size, int a[])//1 -2 -3 -4 5 6 7 8 9 10
{
	//сначала нам нужно найти первое отрицательное число в массиве, чтобы дальше его сравнивать
	int flag =1; //переключатель если все числа вдруг будут положительные
	int max_neg=1;
	for(int i =0; i<size; i++){
		if(a[i]<0){
			flag =0;
			max_neg = a[i];
			break;
		}
	}
	
	if(flag == 1){ //раз все числа положительные выводим ряд как есть, ничего не меняя
		return;
	}
	
	
	
	for(int i =0; i<size; i++){
		if(a[i]<0 && max_neg<a[i]){
		max_neg=a[i];
		}
	}

	//производим замену максимального отрицательного числа и последнего числа в массиве
	for(int i=0; i<size; i++){
		if(a[i] == max_neg){
		int temp = a[i];
		a[i]=a[size-1];
		a[size-1]=temp;
		}
	}


}


	int main(int argc, char **argv)
{
	//формируем массив и считаем количество элементов, хотя не обязательно, так как задан SIZE
	int array[SIZE];
	int number_of_digit = Input_array(array, SIZE);
	printf("number_of_digit = %d\n", number_of_digit); //проверка

	swap_negmax_last(number_of_digit, array);
	
		//выведем результат
	for(int i=0; i<number_of_digit; i++){
		printf("%d ", array[i]);
	}

	return 0;
}


//вариант нейросети
//~ #include <stdio.h>
//~ #define SIZE 10

//~ int Input_array(int array[], int N)
//~ {
	//~ int number_of_digit =0;
	//~ for(int i =0; i<N; i++){
		//~ if(scanf("%d", &array[i])!=1){
			//~ printf("Error");
			//~ return 0;
		//~ }

		//~ number_of_digit ++; //считаем количество заполненных ячеек памяти в массиве
	//~ }
	//~ return number_of_digit;
//~ }


//~ void swap_negmax_last(int size, int a[]) {
    //~ int idx = -1;       // здесь будет храниться индекс максимального отрицательного
    //~ // ищем первый и сразу максимальный отрицательный
    //~ for (int i = 0; i < size; i++) {// 1 -2 -3 -1 5 6 7 8 9 10
//~ /*
//~ a[0]=1 ≥0, a[0] < 0 → 1 < 0 ? Нет → вся if-ветка пропускается
//~ i=1: a[1] = −2 < 0 ? Да  Теперь внутри скобок: idx == -1 → −1 == −1 ? Да.  слагаемому через || достаточно одного истинного, вся вторая часть истинна. idx = 1.
//~ i=2: a[2]=−3 <0, Внутри скобок: idx == -1 → 1 == −1 ? Нет. или a[2] > a[idx] → −3 > a[1] (то есть −2) ? Нет. Пропускаем
//~ i=3: a[3]=−1 <0, a[3] < 0 → −1 < 0 ? Да. Внутри скобок: idx == -1 → 1 == −1 ? Нет. a[3] > a[idx] → −1 > a[1] (−2) ? Да! idx = 3.
//~ i=4…i=8: a[i] положительны, пропускаем.
//~ i=9: a[9]=10 положительное, пропускаем.
//~ */
        //~ if (a[i] < 0 && (idx == -1 || a[i] > a[idx])) {
            //~ idx = i;
        //~ }
    //~ }
    //~ // если нашли хотя бы один отрицательный, меняем его с последним
    //~ if (idx != -1) {
        //~ int tmp       = a[idx];
        //~ a[idx]        = a[size - 1];
        //~ a[size - 1]   = tmp;
    //~ }
	//~ //выведем результат
	//~ for(int i=0; i<size; i++){
		//~ printf("%d ", a[i]);
	//~ }

//~ }


//~ int main(int argc, char **argv)
//~ {
	//~ //формируем массив и считаем количество элементов, хотя не обязательно, так как задан SIZE
	//~ int array[SIZE];
	//~ int number_of_digit = Input_array(array, SIZE);
		//~ printf("number_of_digit = %d\n", number_of_digit); //проверка 
	
	//~ swap_negmax_last(SIZE, array); 

	//~ return 0;
//~ }

