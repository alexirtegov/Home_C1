/*
F11-Сумма минимальна

Дан целочисленный массив из 30 элементов. 
Элементы массива могут принимать произвольные целые значения помещающиеся в int. 
Необходимо создать функцию, которая находит и выводит в порядке возрастания 
номера двух элементов массива, сумма которых минимальна.



Формат входных данных:
Последовательность из 30 целых чисел через пробел
Input
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

Формат результата:
Два целых числа через пробел
Output
0 1

Решение:
путь через поиск двух минимумов сложен тем, что не понятно чем инициализировать 
второй минимум перед циклом, если первый можно инициализировать min1 = array[0], 
то по второму вопрос и придется брать магическое число

Решение от ИИ мне понравилось больше. Мы пробегаем наш массив через два цикла for
и сравниваем пары которые получены от значения внешнего и внутреннего цикла, когда
мы найдем минимальную пару мы найдем минимумы и их индексы. задача будет решена

*/
//вариант быстрый код но не понятная инициализация с магическим числом
//~ #include <stdio.h>

//~ int main() {
    //~ int n;
    //~ scanf("%d", &n); // Считываем размер массива

    //~ int arr[n];
    //~ for (int i = 0; i < n; ++i) {
        //~ scanf("%d", &arr[i]); // Считываем элементы массива
    //~ }

    //~ // Инициализация первого и второго минимальных значений и их индексов
    //~ int min1_index = 0, min2_index = -1;
    //~ int min1_value = arr[0], min2_value = 0;

    //~ // Находим минимум
    //~ for (int i = 1; i < n; ++i) {
        //~ if (arr[i] < min1_value) {
            //~ min1_value = arr[i];
            //~ min1_index = i;
        //~ }
    //~ }

    //~ // Находим второй минимум (другой индекс)
    //~ min2_value = 2147483647; // Максимальное значение int
    //~ for (int i = 0; i < n; ++i) {
        //~ if (i == min1_index) continue;
        //~ if (arr[i] < min2_value) {
            //~ min2_value = arr[i];
            //~ min2_index = i;
        //~ }
    //~ }

    //~ // Вывод индексов (от меньшего к большему)
    //~ if (min1_index < min2_index)
        //~ printf("%d %d\n", min1_index, min2_index);
    //~ else
        //~ printf("%d %d\n", min2_index, min1_index);

    //~ return 0;
//~ }


//вариант 2 через решение ИИ

#include <stdio.h>
#define SIZE 30

void Input_array(int array[], int n)
{
	for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]); 
    }
    return;
}

void Print_index_Minimal_pair(int array[], int n)
{
	int min_index_1=0; //начальная пара 0 и 1
	int min_index_2=1;
	int pair_sum_min= array[0]+array[1];
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			int pair_sum = array[i]+array[j];
			if(pair_sum_min>pair_sum){
				pair_sum_min = pair_sum;
				min_index_1=i;
				min_index_2=j;
			}
		}
	}
	 // выводим индексы по возрастанию
    if (min_index_1 < min_index_2)
        printf("%d %d\n", min_index_1, min_index_2);
    else
        printf("%d %d\n", min_index_2, min_index_1);
}


	
		

int main(int argc, char **argv)
{
	int array[SIZE];
	Input_array(array, SIZE);
	
	Print_index_Minimal_pair(array, SIZE);
	
		
	return 0;
}

