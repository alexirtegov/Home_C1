/*
Задание A17        Какое время года
    Ввести номер месяца и вывести название времени года.
    Формат входных данных
    Целое число от 1 до 12 - номер месяца.
    Формат результата
    Время года на английском: winter, spring, summer, autumn

 */


#include <stdio.h>

int main(int argc, char **argv)
{
	
	int a;
		scanf("%d", &a);
	//~ if (a==12||a==1||a==2)
	//~ printf("winter");
	
	//~ if (a==3||a==4||a==5)
	//~ printf("spring");
	
	//~ if (a==6||a==7||a==8)
	//~ printf("summer");
	
	//~ if (a==9||a==10||a==11)
	//~ printf("autumn");
	
	//~ else
	//~ printf("wrong month");
	
	//через любимый тернарный оператор
	printf("%s\n", (a == 12 || a == 1 || a == 2) ? "winter" :
    (a == 3  || a == 4 || a == 5) ? "spring" :
    (a == 6  || a == 7 || a == 8) ? "summer" :
    (a == 9  || a == 10|| a == 11) ? "autumn" :
                                     "wrong month");
	
	
return 0;
}

