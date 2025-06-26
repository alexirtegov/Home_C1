/*
Шаг 9: данные из интернета

Мы будем использовать бесплатный сервис wttr.in, который не требует API-ключа, 
и библиотеку libcurl для HTTP-запросов плюс cJSON для парсинга.
 
Парсинг (от английского parsing) — это процесс разбора некоторого входного текста 
или потока символов с целью извлечения из него структурированной информации. 
Проще говоря, это превращение “сырого” текста в удобную для программы форму, 
например в набор полей, объектов или узлов дерева.

В программировании парсинг обычно делят на два этапа. Сначала лексический анализ (лексинг) 
разбивает вход на токены — минимальные значимые фрагменты (идентификаторы, числа, знаки препинания и т. д.). 
Затем синтаксический анализ строит из токенов более сложную структуру (дерево разбора, AST), 
проверяя при этом, соответствует ли вход заданному синтаксису.

Пример: когда вы парсите JSON, библиотека (например, cJSON) читает строку вида
{"name":"Alice","age":30}
и выдаёт объект с двумя полями — name и age. После этого в вашем коде вы можете 
обращаться к результату разбора как к обычным переменным или структурам, 
вместо того чтобы вручную искать кавычки, запятые и скобки.


План:

Убираем из main ветку «ручной» и «авто» ввод — оставляем только чтение из файла.

Добавляем новый модуль: FetchWeather, который по переданным широте/долготе 
(или названию города) делает HTTP-GET к wttr.in, получает JSON, разбирает его 
и записывает в файл temperature.txt в том же формате, в котором его сейчас читает FileInput.

В main до вызова FileInput вызываем FetchWeather, чтобы файл всегда был «свежим».

Собираем под Windows с подключением libcurl и cJSON.



Установка libcurl скачать prebuilt-библиотеки с официального сайта https://curl.se/windows/.
или Откройте MSYS2 UCRT64
Обновите базу пакетов и саму систему два раза:
pacman -Syu
Установите libcurl (он подтянет все нужные зависимости):
pacman -S mingw-w64-ucrt-x86_64-curl
В результате в директории /ucrt64/include появится папка curl/, а в /ucrt64/lib – файлы libcurl.a 


Установка cJSON
Репозиторий: https://github.com/DaveGamble/cJSON
Достаточно скопировать файлы cJSON.h и cJSON.c в папку вашего проекта или подключить их через CMake.
При компиляции просто добавляете cJSON.c в список исходников.

 */
#include <curl/curl.h>
#include "cJSON.h"

#include <stdio.h>
#include <stdint.h>
#define SIZE 1000 

struct Memory {
    char *data;
    size_t size;
};
//функцию-коллбэк для libcurl:

static size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t realSize = size * nmemb;
    struct Memory *mem = (struct Memory*)stream;
    char *tmp = realloc(mem->data, mem->size + realSize + 1);
    if (!tmp) return 0;
    mem->data = tmp;
    memcpy(&(mem->data[mem->size]), ptr, realSize);
    mem->size += realSize;
    mem->data[mem->size] = 0;
    return realSize;
}



//ШАГ 1
struct sensor {
    uint8_t day;       // День (1-31) (диапазон 0-255), так как дни/месяцы не превышают 31.
    uint8_t month;     // Месяц (1-12) (диапазон 0-255), так как дни/месяцы не превышают 12.
    uint16_t year;     // Год (4 цифры)
    int8_t t;          // Температура (диапазон 0-255), (температура от -128 до +127). Этого достаточно для большинства регионов.
};

//ШАГ 2
void AddRecord(struct sensor* info, int index, uint16_t year, uint8_t month, uint8_t day, int8_t t) //Функция принимает указатель на массив структур, индекс, а также значения для полей. Заполняет структуру по указанному индексу.
{ 																									//Заполняет поля конкретного элемента массива
	info[index].year = year;
	info[index].month = month;
	info[index].day = day;
	info[index].t = t;
}

//ШАГ 3
int AddInfo(struct sensor* info)
{
	int count =0;	
	AddRecord(info, count++, 2021, 9, 16, 9);  //индекс 0
	AddRecord(info, count++, 2022, 9, 2, -9); //индекс 1
	AddRecord(info, count++, 2021, 1, 7, 8); //индекс 2
	AddRecord(info, count++, 2021, 9, 5, 1); //индекс 3
	
	return count; //возвращаем в main количество записей
}

//ШАГ 6
int ManualInput (struct sensor* info)
{
	int count = 0;
	printf ("maximum amount of memory for data input (max %d): ", SIZE);
	printf("Enter number of records (max %d): ", SIZE);
    scanf("%d", &count);
    
    if(count > SIZE){
		count = SIZE;
	}
	
	for (int i =0; i<count; i++){
		unsigned int year, month, day;
        int t;  // int вместо int8_t
        
        printf("Record #%d (year month day temperature): ", i+1);
        scanf("%u %u %u %d", &year, &month, &day, &t);
        
        // Проверка и приведение типов
        if (year> 65535) year = 65535;
        if (month > 255) month = 255;
        if (day > 255) day = 255;
        if (t < -128) t = -128;
        if (t > 127) t = 127;
        
        AddRecord(info, i, (uint16_t)year, (uint8_t)month, (uint8_t)day, (int8_t)t);
	}
	return count;
}

// ШАГ 7: Функция для чтения данных из файла
int FileInput(struct sensor* info) 
{
	
    FILE* file = fopen("C:\\FILE\\temperature.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    int count = 0;
    unsigned int year, month, day;
    int t;

    while (count < SIZE && 
           fscanf(file, "%u %u %u %d", &year, &month, &day, &t) == 4) {
        // Проверка и приведение типов
        if (year > 65535) year = 65535;
        if (month > 255) month = 255;
        if (day > 255) day = 255;
        if (t < -128) t = -128;
        if (t > 127) t = 127;
        
        AddRecord(info, count, (uint16_t)year, (uint8_t)month, (uint8_t)day, (int8_t)t);
        count++;
    }
    
    fclose(file);
    return count;
}


//ШАГ 1
void Print (struct sensor* info, int count)
{
	printf("===================================\n");
	for(int i =0; i<count; i++){
		printf("%04d - %02d - %02d temperature = %3d\n",
		info[i].year,
		info[i].month,
		info[i].day,
		info[i].t);
		}
}

//ШАГ4 сортировка по возрастанию температуры.
void swap(struct sensor *i, struct sensor *j){ //мы ничего не возвращаем так как работаем меняем сразу по адресам
	struct sensor temp =*i;
	*i = *j;
	*j = temp;
}

void SortByTemperature (struct sensor *info, int count)
{
		for (int i=0; i<count; i++){
			for(int j=i; j<count; j++){
				if(info[i].t>info[j].t){
					swap(&info[i], &info[j]); // передаём указатели (адреса) на соответствующеие структуры
					//~ struct sensor temp = info[i];
					//~ info[i] = info[j];
					//~ info[j] = temp;
				}
			}
		}
}
//ШАГ 5 сортировка по дате через битовое преобразования и операцию или (+)
 //~ unsigned int DateToInt(struct sensor* data) 
 //~ {
	//~ return data->year << 16 | data->month << 8 | data->day;
 //~ }

void SortByDate (struct sensor *info, int count)
{
	for (int i=0; i<count; i++){
		unsigned int value_i = info[i].year << 16 | info[i].month << 8 | info[i].day;
			for(int j=i; j<count; j++){
				unsigned int value_j = info[j].year << 16 | info[j].month << 8 | info[j].day;
				if(value_i > value_j){
					swap(&info[i], &info[j]);
					//~ struct sensor temp = info[i];
					//~ info[i] = info[j];
					//~ info[j] = temp;
				}
				
				
				//через DateToInt
				//~ if(DateToInt(&info[i]) > DateToInt(&info[j])){ // передаём указатели (адреса) на соответствующеие структуры
					//~ swap(&info[i], &info[j]);
					//~ struct sensor temp = info[i];
					//~ info[i] = info[j];
					//~ info[j] = temp;
				//~ }
			}
		}
}

// Запрос к wttr.in для получения прогноза на ближайшие 3 дня 
int FetchWeatherAndWriteFile(const char *location, const char *out_path) {
    CURL *curl = curl_easy_init();
    if (!curl) return -1;

    struct Memory chunk = { .data = NULL, .size = 0 };
    // Формируем URL: wttr.in/<location>?format=j1
    char url[256];
    snprintf(url, sizeof(url), "https://wttr.in/%s?format=j1", location);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
    // опционально отключить верификацию SSL (если нет CA):
    // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    if (curl_easy_perform(curl) != CURLE_OK) {
        curl_easy_cleanup(curl);
        free(chunk.data);
        return -2;
    }
    curl_easy_cleanup(curl);

    // Парсим JSON
    cJSON *root = cJSON_Parse(chunk.data);
    free(chunk.data);
    if (!root) return -3;

    cJSON *weather = cJSON_GetObjectItem(root, "weather");
    if (!weather || !cJSON_IsArray(weather)) {
        cJSON_Delete(root);
        return -4;
    }

    FILE *out = fopen(out_path, "w");
    if (!out) {
        cJSON_Delete(root);
        return -5;
    }

    // Перебираем каждый день прогноза
    int count = cJSON_GetArraySize(weather);
    for (int i = 0; i < count; i++) {
        cJSON *day = cJSON_GetArrayItem(weather, i);
        cJSON *date = cJSON_GetObjectItem(day, "date");         // строка "YYYY-MM-DD"
        cJSON *avgtemp = cJSON_GetObjectItem(day, "avgtempC");  // строка с температурой в градусах

        if (date && avgtemp && cJSON_IsString(date) && cJSON_IsString(avgtemp)) {
            int y, m, d, t;
            if (sscanf(date->valuestring, "%d-%d-%d", &y, &m, &d) == 3) {
                t = atoi(avgtemp->valuestring);
                // Ограничиваем диапазон
                if (t < -128) t = -128;
                if (t > 127)  t = 127;
                fprintf(out, "%04d %02d %02d %d\n", y, m, d, t);
            }
        }
    }

    fclose(out);
    cJSON_Delete(root);
    return 0;
}

int main(int argc, char **argv)
{
		
    struct sensor info[SIZE];
    // 1. Берём свежие данные в файл
   if (FetchWeatherAndWriteFile("Solikamsk+Perm", "C:\\FILE\\temperature.txt") != 0) {
        printf("Не удалось получить данные из интернета\n");
        return 1;
    }
    // 2. Читаем из файла
    int Count = FileInput(info);
    if (Count == 0) {
        printf("Нет ни одной записи в файле\n");
        return 1;
    }
    // 3. Выводим и работаем как раньше
    printf("\nInitial data:");
    Print(info, Count);
	
	//ШАГ 1
	printf("\nInitial data:");
	Print(info, Count);
	
	//ШАГ8
	// Новый интерактивный цикл
    char command;
    do {
        printf("\nChoose action:\n");
        printf("(T) Sort by Temperature\n");
        printf("(D) Sort by Date\n");
	//ШАГ9 ---------------------------------
        printf("(C) Coldest day\n");
        printf("(H) Hottest day\n");	
    //--------------------------------------    
        printf("(E) Exit\n");
        printf("Enter command: ");
        scanf(" %c", &command);
        
        
        switch(command) {
            case 't':
                SortByTemperature(info, Count);
                printf("\nSorted by temperature:");
                Print(info, Count);
                break;
                
            case 'd':
                SortByDate(info, Count);
                printf("\nSorted by date:");
                Print(info, Count);
                break;  
	//ШАГ9 ---------------------------------                
            case 'c': {
                int min = 0;
                for(int i = 1; i < Count; i++)
                    if(info[i].t < info[min].t){
						 min = i;
					 }
					 
                printf("\nColdest day: %04d - %02d - %02d temperature = %3d\n",
                    info[min].year, info[min].month, info[min].day, info[min].t);
                break;
            }

            case 'h': {
                int max = 0;
                for(int i = 1; i < Count; i++)
                    if(info[i].t > info[max].t){
						 max = i;
					 }
                printf("\nHottest day: %04d - %02d - %02d temperature = %3d\n",
                    info[max].year, info[max].month, info[max].day, info[max].t);
                break;
            }
    //--------------------------------------              
                     
            case 'e':
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid command! Please try again.\n");
        }
    } while(command != 'e');
    

	return 0;
}

