#include <stdio.h>

int main(void){
FILE *f;
    //~ static char filename[100]={0};
    size_t size;
    
    //~ printf("Input file name: ");
    //~ scanf("%s",filename);
    
     // можно прямо указать путь к файлу:
    const char *filename = "C:\\FILE\\sum.txt";
    
    f = fopen (filename, "r");
    if (f != NULL) {
        fseek (f, 0, SEEK_END);//fseek двигает указатель в 
        //SEEK_END в конец оттуда возвращает на 0 байт
        size = ftell (f);
        //Функция ftell возвращает текущую позицию в файле в байтах, считая от начала.
        fclose (f);
        printf ("File size of '%s' - %zu bytes.\n",filename, size);
    } else {
        printf ("Can't open file %s\n", filename);
    }
    return 0;
}
