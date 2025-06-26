/*

 */


#include <stdio.h>

//ручное объявление функции из другого модуля
extern int max(int a, int b);

int main(int argc, char **argv)
{
	int a, b;
	printf("please, input two meaning\n");
	scanf("%d %d", &a, &b);
	int m = max(a, b);
	
	printf("max = %d", m);
	
	return 0;
}

