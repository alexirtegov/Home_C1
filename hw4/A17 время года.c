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
		
		//вариант 1
		
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
	
	
	
	//вариант 2 через любимый тернарный оператор
	
	//~ printf("%s\n", (a == 12 || a == 1 || a == 2) ? "winter" :
    //~ (a == 3  || a == 4 || a == 5) ? "spring" :
    //~ (a == 6  || a == 7 || a == 8) ? "summer" :
    //~ (a == 9  || a == 10|| a == 11) ? "autumn" :
                                     //~ "wrong month");
                                     
   
   
    //вариант 3 через switch
    if(a>=1&&a<=12){
		
    switch(a){
		case 12:
		case 1:
		case 2:
		printf("winter");
		break;
		
		case 3:
		case 4:
		case 5:
		printf("spring");
		break;
		
		case 6:
		case 7:
		case 8:
		printf("summer");
		break;
		
		case 9:
		case 10:
		case 11:
		printf("autumn");
		break;
		
	}
}
else
	printf("wrong month");
return 0;
}

