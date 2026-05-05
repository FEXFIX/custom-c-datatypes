//include guards
#ifndef MYINT32_H
#define MYINT32_H

typedef struct{
    unsigned char bytes[4];
    //space for other vars in the future maybe
} myint32;


myint32 myint32_from(long val); // long for portability
long myint32_to(myint32 n);


// constant methods
myint32 myint32_zero(void);
myint32 myint32_min(void);
myint32 myint32_max(void);

//sign-operations
unsigned char myint32_is_negative(myint32 n);
unsigned char myint32_is_zero(myint32 n);

myint32 myint32_negate(myint32 n);
myint32 myint32_abs(myint32 n);

//arithmetic
myint32 myint32_add(myint32 a, myint32 b);
myint32 myint32_sub(myint32 a, myint32 b);

myint32 myint32_inc(myint32 n);
myint32 myint32_dec(myint32 n);



#endif /* MYINT32_H */