
#include <stdio.h>

int main(int argc, char **argv)
{
	//создаем путь к файлу
	const char *filepath = "C:\\FILE\\sum.txt";
	
	//открываем файл для чтения
	FILE*file;
	
	file = fopen(filepath, "r");
	if(file == NULL) {
        printf("Failed to open file for reading\n");
        return 1;
    }
    
    int sum =0;
    int n;
    
    while(fscanf(file, "%d", &n) == 1){
		printf("read the number = %d\n", n);
		sum +=n;
	}
	
	fclose(file);
	
	printf("sum all of number = %d", sum);
	
	return 0;
}

