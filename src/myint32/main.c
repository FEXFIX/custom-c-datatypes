#include <stdio.h>
#include "myint32.h"

void fibonacci(int steps) {
    myint32 a = myint32_from(0);
    myint32 b = myint32_from(1);
    myint32 c;
    int i;
    printf("Fibonacci: ");
    printf("%ld ", myint32_to(a));
    printf("%ld ", myint32_to(b));
    for (i = 2; i < steps; i++) {
        c = myint32_add(a, b);
        printf("%ld ", myint32_to(c));
        a = b;
        b = c;
    }
    printf("\n");
}


int main(void){
    long val;
    printf("enter test-value: ");
    scanf("%ld", &val);
    myint32 x = myint32_from(val);

    for (int i = 0; i < 4; i++) {
        printf("%02X ", x.bytes[i]);
        
    }
    printf("\n");

    unsigned char check = myint32_is_negative(x);
    printf("%u\n", check);

    long back = myint32_to(x);
    printf("\nRECONSTRUCTED VALUE:\n");
    printf("%ld\n", back);
    printf("\n");
    

    fibonacci(12);
    
    return 0;
}