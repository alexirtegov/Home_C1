/*
Программа хранит информацию о людях (имя, фамилия, возраст) 
с помощью структуры. Она позволяет автоматически добавлять 
"стандартных" студентов, выводить их на экран и анализировать 
такие данные:

Какой максимальный возраст среди них;
Сколько людей с данным именем;
Сколько людей имеют однофамильцев 
(т.е. фамилия совпадает хотя бы с ещё одним человеком).


1. Описать структуру для предоставления информации о человеке: 
фамилия(не более 30 символов)
имя (не более 30 символов)
возраст

2. Описать функцию, которая для заданного массива из описанных структур определяет:
-возраст самого сташего
-количество людей с заданным именем (имя также параметр функции)
-количество людей, у которых есть однофамильцы
 */

//1) подключаем библиотеки:
#include <stdio.h>  //для функции ввода/вывода (printf).
#include <stdint.h> //для стандартных целочисленных типов (uint8_t — беззнаковый байт 0...255, удобен для возраста).
#include <string.h> //для работы со строками (strcpy, strcmp).

//2) определяем константы:
#define STR_SIZE 30 // максимальная длина имени/фамилии (30 символов).
#define STUDEN_NUMBER 200 // максимальное число студентов в массиве (200).


//3) описываем структуру
struct student { //структура которая будет хранить:
    char surname[STR_SIZE]; //массив фамилия
    char name[STR_SIZE]; //массив имя
    uint8_t age; // возраст
};


// 4) функция поиска возраст самого старшего человека;
int Eldest(struct student* course,int number){ //получаем указатель на массив course[]
    int max = course[0].age; // int max = course->age;
    for(int i=1;i<number;i++)
        if(max < course[i].age) //  if(max < (course+i)->age)
            max = course[i].age; // max = (course+i)->age;
    return max;
}

//5) функция поиска количество людей с заданным именем (имя также является параметром функции);
int SameNameNumber(struct student* course,int number,char* name)
//Опрашивает каждого студента — если имя совпадает с нужным, увеличивает счётчик.
{
    int counter = 0;
    for(int i=0;i<number;i++)
        if(strcmp(course[i].name,name) ==0) //в СИ если значения совпадают strcmp(str1, str2) == 0
            counter++;
    return counter;
}

//6) функция поиска однофамильцев:
int Namesakes(struct student* course,int number){
	//Внешний цикл идёт по всем студентам (кроме последнего).
	//Внутренний цикл сравнивает каждого студента с теми, 
	//кто после него в списке.
	//Если находит совпадение фамилии — увеличивает счётчик 
	//(и сразу переходит к следующему студенту, чтобы не считать 
	//одного несколько раз).

    int counter=0;
    for(int i=0;i<number-1;i++)
        for(int j=i+1;j<number;j++)
            if(strcmp(course[i].surname, course[j].surname) == 0)
            {
                counter++;
                break;
            }
    return counter;
}


//7) функция добавления студента:
//Просто копирование данных в очередной элемент массива студентов.
void AddStudent(struct student* course, int number, 
				char* surname,char* name,int age)
{
    course[number].age = age;
    strcpy(course[number].name,name);
    strcpy(course[number].surname,surname);
    
    //для AddStudent(course,c++,"Ivanov","Ivan",18);
    //передаем
    //course[0].age = 18; заносим в структуру
    //strcpy(course[0].name,Ivan); заносим в структуру
    //strcpy(course[0].surname,Ivanov);заносим в структуру
}


//8) печать массива студента
void print(struct student* course,int number){
	//Выводит всех студентов из массива — фамилия, имя, возраст.
    for(int i=0;i<number;i++)
        printf("%s\t%s\t%d\n", course[i].surname, course[i].name, course[i].age);
}


//9) набор студентов
int AddCourse(struct student course[]){
    int c=0;
    AddStudent(course,c++,"Ivanov","Ivan",18);
    AddStudent(course,c++,"Petrov","Ivan",19);
    AddStudent(course,c++,"Petrov","Ivan",19);
    AddStudent(course,c++,"Petrov","Ivan",19);
    AddStudent(course,c++,"Petrov","Ivan",19);
    AddStudent(course,c++,"Ivanov","Vasily",44);
    return c;
}


//10) главная функция
int main(void)
{
    struct student course1[STUDEN_NUMBER]; // массив из 200 структур
    struct student course2[STUDEN_NUMBER]; // массив из 200 структур
    
    int number1=AddCourse(course1); // добавляет 6 студентов
    int number2=AddCourse(course2); // тоже 6 во второй массив, для тестов
   
    print(course1,number1); // вывести всех студентов course1
    
    printf("Eldest student = %d\n",Eldest(course1,number1));
    // максимальный возраст
    
    char* name = {"Ivan"};
    printf("Name %s number = %d\n",name,SameNameNumber(course1,number1,name));
    // сколько студентов с именем "Ivan"
    
   
    printf("Same surname number = %d\n",Namesakes(course1,number1));
    // сколько однофамильцев
    
    
    return 0;
}
