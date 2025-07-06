/*
### 📚 Урок 2: Указатели на структуры и оператор `->`

**Объяснение:**
Иногда мы работаем не с самой структурой, а с указателем на нее. 

Это особенно полезно:
- При передаче структур в функции (чтобы избежать копирования больших данных)
- При динамическом выделении памяти

Для доступа к полям структуры через указатель используется оператор 
`->` (стрелка).

Пример: 
struct Book *ptr = &my_book;
printf("Title: %s\n", ptr->title);  // Вместо (*ptr).title

Задание:
Объявите указатель на структуру Book
Сделайте так, чтобы он указывал на Book_one
Через указатель измените год издания на 1988 и цену на 39.99
Выведите измененные значения через указатель
(Дополнительно) Создайте функцию print_book(), 
которая принимает указатель на структуру и 
выводит информацию о книге

 */


#include <stdio.h>
#include <string.h>

struct Book {
	char title [100];
	char author [50];
	int year;
	float price;
};

void print_book(struct Book *b_1)
{
	printf("Book name: %s, author: %s, year: %d, price: %.2f\n", 
	b_1 -> title, 
	b_1 -> author, 
	b_1 -> year, 
	b_1 -> price);
	
	
}

int main(int argc, char **argv)
{
	//вариант 1 Поэлементное присваивание после объявления
	struct Book Book_one; 
	strcpy(Book_one.title, "The C Programming Language");
	strcpy(Book_one.author, "K&R");
	Book_one.year = 1978;
	Book_one.price = 29.99;
	
	printf("Book name: %s, author: %s, year: %d, price: %.2f\n", Book_one.title, Book_one.author, Book_one.year, Book_one.price);
	
	//вариант 2 инициализация при объявлении
	struct Book Book_two = {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 12.99};
	printf("Book name: %s, author: %s, year: %d, price: %.2f\n", Book_two.title, Book_two.author, Book_two.year, Book_two.price);
	
	//работа с указателем
	struct Book*b_1 = &Book_one;
	b_1 ->year = 1988;
	b_1 ->price = 39.99;
	
	print_book(b_1);
	
	return 0;
}
