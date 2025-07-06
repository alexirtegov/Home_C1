/*
Этап 3: Добавляем вывод размера файлов.

Для получения размера файла будем использовать функцию stat.
Подключим <sys/stat.h>.
Для каждого файла получим его полный путь (full_path + имя файла) и вызовем stat.
Выведем размер рядом с именем.

### Пример работы программы
Предположим, у нас есть директория `/home/user/documents` с файлами:
- `report.txt` (размер 1500 байт)
- `image.jpg` (размер 2500000 байт)
- `.hidden` (скрытый файл, не будет показан)

**Взаимодействие:**
```
Input dir: documents
Files in folder /home/user/documents/:
report.txt            1 Kb
image.jpg             2 Mb
Total: 2 files
```
*/

#include <stdio.h> // Для функций ввода-вывода (printf, scanf, perror)

#include <string.h>  //нужен для работы со строками: там объявлены strlen, strcpy, strcat.
// здесь size_t strlen(const char *s)
// получает указатель на строку s, идёт по символам до первого '\0' 
//и возвращает число пройденных символов (не включая завершающий нуль). 
//Например, для строки "hello" она вернёт 5.

#include <unistd.h>  // содержит прототип getcwd (получение текущей директории).
//Функция getcwd(full_path, PATH_LENGTH); записывает в этот буфер текущий рабочий каталог.
//Параметры функции `getcwd`:
//- Первый параметр: указатель на буфер, куда будет записан путь.
//- Второй параметр: размер этого буфера.

#include <dirent.h> //даёт функции для работы с директориями: opendir, readdir, closedir, и тип struct dirent.
#include <sys/stat.h> //// Для функции stat (получение информации о файле)

enum { PATH_LENGTH = 256 }; //создаёт в области компиляции целочисленную константу PATH_LENGTH, равную 256

//#define PATH_LENGTH 256 - просто текстом подставялется 256
#define STR255 "%255s"



void convert_path_to_full(char *full_path, const char *dir) {
    if (dir[0] == '/') {
        strcpy(full_path, dir);          // Абсолютный путь (начинается с /), при совпадении копируем strcpy из массива dir строку в full_path как есть
		//strcpy копирует строку из массива dir в массив full_path

    } else if (dir[0] == '.') {
        getcwd(full_path, PATH_LENGTH);  // Относительный путь с точкой (текущая директория)
        //getcwd(full_path, PATH_LENGTH) заполняет массив full_path (длина 256) строкой адреса рабочего каталога вида "/home/user/project".
        
    } else {
        getcwd(full_path, PATH_LENGTH);  // относительный путь без точки (просто имя папки)
        strcat(full_path, "/"); //strcat  добавляет вторую строку с символом / в конец первой.
        strcat(full_path, dir); // Теперь добавляем к `full_path` строку `dir` (введенную пользователем).
    }
   
    if (full_path[strlen(full_path) - 1] != '/')
    //мы читаем full_path и считаем длину массива, сравниваем последний с '/' и если '/' нет, добавлем
        strcat(full_path, "/"); //добавляем '/' если его нет
}

void print_file_size(long long int byte_number) { //Эта функция печатает размер файла в удобочитаемом формате (байты, килобайты, мегабайты).
    if (byte_number >= 1024 * 1024)
        printf("%lld Mb", byte_number / (1024 * 1024)); // Размер в мегабайтах
    else if (byte_number >= 1024)
        printf("%lld Kb", byte_number / 1024); // Размер в килобайтах
    else
        printf("%lld b", byte_number); // Размер в байтах
/*
**Примеры:**
- 2500000 байт -> 2 Mb (примерно, так как 2500000 / (1024*1024) ≈ 2.38, но целочисленное деление даст 2)
- 1500 байт -> 1 Kb (1500/1024 ≈ 1.46, целочисленное деление даст 1)
- 500 байт -> 500 b
*/
}


int main() 
 {
	 //объявление переменных
    char dir[PATH_LENGTH]; //Запрашивает у пользователя путь
    char full_path[PATH_LENGTH];
    
    //ввод пути от пользователя
    printf("Input dir: "); 
    fgets(dir, PATH_LENGTH, stdin);  // Безопасный ввод (до 255 символов)
    dir[strcspn(dir, "\n")] = '\0';
    
    //преобразование введенного пути в абсолютный
    convert_path_to_full(full_path, dir);
    printf("Files in folder %s:\n", full_path); //выведет только адрес рабочего каталога

    //Открытие директории
    
    //В заголовке <dirent.h> (POSIX-стандарт) объявлен тип typedef struct __dirstream DIR;
    //где __dirstream – внутренняя реализация этой структуры.
    //То есть DIR — это через typedef переименованная внутренняя структура (обычно struct __dirstream)
    //DIR *folder это указатель на DIR
    DIR *folder = opendir(full_path); //открыть каталог с именем name (ваш full_path)
   //внутри себя выделяет (или инициализирует) область памяти под объект типа DIR, заполняет туда служебные поля
   //Если он вернул NULL, значит не получилось открыть папку 
   //(нет прав, нет такой папки и т. п.) 
   //и мы выводим системную ошибку через perror и завершаем программу.
   //«НЕ-NULL указатель» — указатель указывает на реальную область памяти, а не равен нулю.
   
      if (folder==NULL) {
        perror("Unable to read directory");
        return 1;
    }
    
    //Чтение содержимого директории
    struct dirent *entry; 	// Информация о файле
    struct stat file_stats;	// Информация о размере
    
    int count = 0;
    
    // Цикл по всем элементам директории
    while ((entry = readdir(folder))) {
        // Пропускаем скрытые файлы и директории (начинающиеся с '.')
        if (entry->d_name[0] == '.') 
            continue;
            
        // Формируем полный путь к файлу
        char file_path[PATH_LENGTH]; //новый массив
        strcpy(file_path, full_path); // Копируем путь папки из массива full_path
        strcat(file_path, entry->d_name); // Добавляем имя файла в конец пути

        // Получаем информацию о файле
        if (stat(file_path, &file_stats) == -1) { //stat(file_path, &file_stats)` пытается получить информацию о файле по пути `file_path` и записать её в структуру `file_stats`.
            perror("stat error");
            continue;
        }
        
		// Печатаем имя файла и его размер
        printf("%-20s\t", entry->d_name);	// Имя файла
        print_file_size(file_stats.st_size); // Размер
        printf("\n");
        count++;
    }

	//Закрытие директории и завершение
    closedir(folder);
    return 0;
}
