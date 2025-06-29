/*
1.открываем файл (если нет создается) для записи в двоичном виде  (wb: write binary).
2. записываем данные в файл
fwrite — записывает данные в файл.
&i — адрес переменной i (чтобы записать её содержимое).
sizeof(int) — сколько байт занимает int на твоей системе (обычно 4 байта).
1 — количество таких объектов (один int).
f — куда писать.

То есть: мы записываем 4 байта (значение i) в файл.
Если представить в 16-ричных байтах:
0x31323334 будет храниться в памяти 
(на большинстве современных компьютеров, 
где используется формат little-endian — 
младший байт первый!) так:

Байт №	Значение
0	0x34
1	0x33
2	0x32
3	0x31

В файле будут записаны байты: 34 33 32 31 (четыре байта).
В 16-ричной записи эти байты подряд:
0x31 (старший байт), 0x32, 0x33, 0x34 (младший байт)

3. Открываем файл снова, но теперь для чтения в двоичном режиме (rb: read binary).
4. Читаем:
fread читает данные из файла.
&u — куда сохранять прочитанное (адрес переменной u).
1 — размер одного элемента (1 байт).
1 — количество таких элементов (то есть ровно 1 байт).
f — из какого файла читать.


В итоге: для fread (&u, 1, 1, f);
В переменную u ПОПАДАЕТ ПЕРВЫЙ БАЙТ ФАЙЛА.
Первым байтом был 0x34 (52 в десятичной). 
Остальные 3 байта переменной u ОСТАЮТСЯ равными 0, 
потому что мы читаем только один байт, 
не заполняя все байты переменной.


Что делает программа?
Программа создаёт двоичный файл и записывает в него значение 0x31323334 как 4 байта.
Потом файл открывается снова, и читается только первый (самый младший!) байт.
Именно этот байт — это 0x34, т.е. младший байт того числа.
На экран выводится это значение в шестнадцатеричном формате — 34.

Пояснение о little-endian
Почему первым байтом оказался 0x34?
Потому что большинство ПК используют порядок хранения байт little-endian: 
младший байт по меньшему адресу, старший — по большему. То есть если значение 
0x31323334, то в памяти и в файле это будет: 34 33 32 31 
(если читать по байтам "слева направо" в файле).

 */

#include <stdio.h>

int main(void){
    unsigned int i = 0x31323334, u=0; //это шестнадцетиричное число в десятиричном виде 825373492
		
		unsigned char *p = (unsigned char*)&i;
		printf("%x %x %x %x\n", p[0], p[1], p[2], p[3]);
		printf("%x %x %x %x\n", *p, *(p+1), *(p+2), *(p+3)); //аналогичная запись
    
    FILE *f = fopen ("C:\\FILE\\out.bin", "wb"); //для записи в двоичном виде (wb: write binary).
    if (f == NULL) {
		printf("Failed to open file for reading\n");
		return 1; // или любая другая обработка ошибки
	}
	
    fwrite (&i, sizeof (int), 1, f); // данные запишутся в формате little-endian
    fclose(f); //закрываем файл

    f = fopen ("C:\\FILE\\out.bin", "rb");//Открываем файл снова,
    // но теперь для чтения в двоичном режиме (rb: read binary).
    
    
    fread (&u, 1, 1, f);
    //1 — размер одного элемента (1 байт).
	//1 — количество таких элементов (то есть ровно 1 байт).
    fclose(f);
    printf("u = %x\n",u); // u = 34
    return 0;
}
