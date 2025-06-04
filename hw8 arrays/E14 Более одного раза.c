/*
E14-Более одного раза

Считать массив из 10 элементов и выделить 
в другой массив все числа, которые встречаются 
более одного раза. В результирующем массиве 
эти числа не должны повторяться.



Формат входных данных:
10 целых чисел через пробел
1 2 3 4 5 1 2 3 4 5

1 2 3 4 5 1 2 1 2 7

Формат результата:
Целые числа через пробел, которые встречаются 
более одного раза в исходном массиве.
1 2 3 4 5

1 2
*/





#include <stdio.h>
#define SIZE 10

void Input(int array[], int n)
{
	for(int i = 0; i<n; i++){ 
		if(scanf("%d", &array[i])!=1){ // перебирая i записываеем значения в каждю ячейку памяти
			printf("Error");
		}
	}
}

void Print_arr(int arr[], int n)
{
	for(int i = 0; i<n; i++){
		printf("%d ", arr[i]); //вывод arr[]
	}
}

int Transfer_number_more_then_one_time(int array[], int arr[], int n) //1 2 3 4 5 1 2 3 4 5 => 1 2 3 4 5
{
	int count = 0;
	
	for(int i=0; i<n; i++){ 
		int already =0;
		for(int k =0; k<count; k++){ //перебераем все члены нового массива чтобы исключить повторение и не взять не правильный i
			if(array[i] == arr[k]){//сравнивваем все члены массива arr[k] с одним членом array[i]
				already = 1;// если нанши совпадение значит already =1 и 
				break; //выходим из внутреннего цикла во внешний для для того чтобы взять следующий член i
			}
		}
		if(already!=1){
			
			for(int j=i+1; j<n; j++){// в этот цикл мы попадаем по условию if(already!=1)
				
				if(array[i] == array[j]){ //например для 1 2 1 2 1 2 array[0]=array[2]
				arr[count] = array[i]; //запишем в arr[count] на место 0 значение 1 arr[0]=1
				count ++; //1
				break;
				}
			}
		
		}
	
	}
	return count;
}	


int main(int argc, char **argv)
{
	int array[SIZE]={0}; //создаем массив в который будем записывать значения
	Input(&array[0], SIZE); // создаем функцию в которую будем записывать значения
	int arr[SIZE]={0};
	
	int COUNT = Transfer_number_more_then_one_time(&array[0], &arr[0], SIZE);//мы получаем значение count равным количеству совпдание, таким образом мы получаем массив ровно с количеством совпадений
	
	Print_arr(&arr[0], COUNT);
	
	
		
	return 0;
}

