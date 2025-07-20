/*
Функция malloc выделяет непрерывный участок динамической памяти заданного размера и 
возвращает адрес первого байта этого участка. Тип возвращаемого значения — void *, то есть «обобщённый указатель».


struct Node* current = head; означает следующее:
	struct Node* current — объявление переменной-указателя current, которая может указывать на структуру типа Node.
	= head — инициализация, т.е. текущий указатель current начинает указывать туда же, куда и head.
	указатель current начинает указывать туда же, куда и head: на первый элемент списка, потому что мы в него записываем адресс head
	
Что лежит в head? когда мы делаем head = malloc(sizeof(struct Node));
	функция malloc выделяет участок динамической памяти, достаточный, чтобы туда поместилась структура Node.
	malloc возвращает значение-указатель типа void *, то есть адрес только что выделенного блока.
	Таким образом, head хранит конкретный адрес только что выделенного блока памяти
	«Обобщённость» касается лишь того, что компилятор пока не знает, на объект какого типа указывает адрес
	Вы копируете адрес из malloc (void*) в head (struct Node*), то есть присваиваете указатель в указатель,
 */


// Пример организации стека как однонаправленного списка#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

//объявляем структуру узла
struct Node
{
	int data;
	struct Node *next; //указатель на следующую структуру
};


int main()
{
	//1. Объявляем указатель на первый элемент
	struct Node*head = malloc(sizeof(struct Node));
	head ->data = 10; 	
	head ->next= NULL;
	
	// 3. Создаем второй узел
	struct Node* second = malloc(sizeof(struct Node));
	second ->data = 20;
	second ->next = NULL; 
	
	
	//5. Создадим третий узел
	struct Node *third = malloc(sizeof(struct Node)); //явное приведение к типу struct Node* избыточно, требуется подключение библиотеки <stdlib.h>
	third ->data = 30;
	third ->next = NULL; 	// изначально третий — тоже «конец»
	
	// 6. Связываем узлы
	//~ head->next = second;
	//~ second->next = third; 
	
	(head->next = second)->next = third;
	
	//7. Работаем со списком через current
	printf("Output of list elements:\n");
	struct Node* current = head; // начинаем с начала списка
	while(current!=NULL){
		printf("%d ", current->data);
		current = current->next;// переходим к следующему элементу
	}
	
	
	
	//8. Освобождаем память (важно!)
	free(head);
	free(second);
	free(third);

	
    return 0;
}

//Визуализация в памяти:
//head [0x1000]  -->  [Первый узел по адресу 0x1000]
//								data: 10
//								next: 0x2000  -->  [Второй узел по адресу 0x2000]
//															data: 20
//															next: 0x3000	-->		[Третий узел по адресу 0x3000]	
//																								data: 30
//																								next: NULL
