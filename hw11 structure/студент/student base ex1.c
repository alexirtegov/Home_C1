/*
🔹 Шаг 1: Базовая структура и вывод одного студента

Задача: Создать структуру student и вывести данные одного студента.
Что делаем:

Объявляем структуру с полями: surname, name (массивы char), age (uint8_t).
В main создаём экземпляр структуры.
Заполняем данные через strcpy и присваивание.
Выводим данные через printf.
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define STR_SIZE 30

struct student{
	char surname[STR_SIZE];
	char name [STR_SIZE];
	uint8_t age;
};

int main(int argc, char **argv)
{
	struct student s = {"Ivanov", "Ivan", 18};
	
	//~ strcpy(s.surname, "Ivanov");
	//~ strcpy(s.name, "Ivan");
	//~ s.age = 18;
	
	printf("%s %s %d\n", s.surname, s.name, s.age);
	
	return 0;
}

