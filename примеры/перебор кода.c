#include <stdio.h>

int main(void) 
{
int secret_code = 123;
int enter_code;




do{
	printf("please enter secret code:");
	
	scanf("%d", &enter_code);
	if(enter_code!=secret_code)
		printf("\nwrong, try again\n");

	
}
	while(enter_code != secret_code);
	
	printf("\nAccess is allowed\n");





    return 0;
}
