

#include <stdio.h>

//умножение 
#define multiplication_1(a1, b1) a1*b1

//умножение со скобками и без
#define multiplication_2(a, b) ((a)*(b)) 
#define multiplication_3(a, b) a*b 
#define TEXT(a, b) "multiplication (" #a ") * (" #b")=100 or multiplication " #a"*"#b"=43 \n"

#define TEXT2 "\ntwo diffrent entries:"

#define print_f "\nsum= %d\n"
#define print_f1 printf("sum= %d\n", sum)

int main(void)
{
	
	int res1 = multiplication_1 (2, 5);
		printf("res1= %d\n", res1);
	
	int x=5, y=7;
	int res2 = multiplication_2 (x+5, y+3); //из-за скобок ввызове define умножение будет (x+5)*(y+3)=10*10
		printf("res2= %d\n", res2);
	int res3 = multiplication_3 (x+5, y+3);	//из-за отсутсвия скобок в вызове define умножение будет x+5*y+3=5+35+3=43
	    printf("res3= %d\n", res3);
		printf("res2 and res3 difrent " TEXT  (x+5, y+3));
		
	
	printf(TEXT2);	
	int sum=x+y;
		printf(print_f, sum);
		print_f1;
		//~ printf("sum = %d\n", sum);
		
	
	
	return 0;
}

