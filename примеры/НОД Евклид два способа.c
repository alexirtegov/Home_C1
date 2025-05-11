#include <stdio.h>

int main(void) {
    int a = 14, b = 35;
    int count = 0;
    printf("a=%d,b=%d, ", a, b);
    
    //вариант 1 - классический Евклид
    //~ while (a != b) {
        //~ if (a > b) {
            //~ a = a - b;
        //~ } else {
            //~ b = b - a;
        //~ }
        //~ ++count;
    //~ }
    
    
    //вариант 2 модифицированный Евклид
while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
    ++count;
}


    printf("NOD=%d, steps=%d\n", a, count);
    return 0;
}
