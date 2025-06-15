#include <stdio.h>

int main() {
	
	//прописываем путь к файлу
	const char *filepath = "C:\\FILE\\myfile.txt";
	
    // 1. Открываем файл для записи
    FILE *file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return 1;
    }
    // 2. Пишем строку в файл
    fprintf(file, "I love my Lisa!\n");
    // 3. Закрываем файл после записи
    fclose(file);

    // 4. Открываем файл для чтения
    file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Failed to open file for reading\n");
        return 1;
    }
    // 5. Читаем и выводим содержимое файла
    char buffer[256];
    while (fgets(buffer, 256, file)) {
        printf("%s", buffer);
    }
    // 6. Закрываем файл после чтения
    fclose(file);

    return 0;
}
