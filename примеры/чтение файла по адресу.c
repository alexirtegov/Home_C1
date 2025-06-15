#include <stdio.h>

int main() {
	
	//прописываем путь к файлу
	const char *filepath = "C:\\FILE\\newfile.txt";
	
    // 1. Открываем файл для чтения
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return 1;
	}

    // 5. Читаем и выводим содержимое файла
    char buffer[256]; //будет читать файл любого размера по кускам 256 байт
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    // 6. Закрываем файл после чтения
    fclose(file);

    return 0;
}
