#include "myint32.h"
#include <stdio.h>
#include <stdint.h>

myint32 myint32_zero(void){
    myint32 r = {0};
    return r;
}

myint32 myint32_max(void){
    myint32 r;
    r.bytes[0] = 0xFF;
    r.bytes[1] = 0xFF;
    r.bytes[2] = 0xFF;
    r.bytes[3] = 0x7F; // we shouldnt fill all for signed-overflow reasons
    return r;
}

myint32 myint32_min(void) {
    myint32 r;
    r.bytes[0] = 0x00;
    r.bytes[1] = 0x00;
    r.bytes[2] = 0x00;
    r.bytes[3] = 0x80; // at least one bit at the start
    return r;
}

myint32 myint32_from(long val) {
    myint32 r = myint32_zero();

    unsigned int u = (unsigned long)val;

    //We cant just select our wished bytes of the bits like indexes, ...
    //instead we need to shift bits and align them with FF/11111111 via a logic op AND
    
    //This took me 6hours to fully understand but its the same shifting-flow as holding -> arrow in a terminal going through each char
    for (int i = 0; i < 4; i++) {
        r.bytes[i] = (u >> (8 * i)) & 0xFF;
    }
    
    return r;
}

long myint32_to(myint32 n){
    unsigned long u = 0;

    //reversing the AND 0xFF process of the from function by simply OR'ing the input bits for each byte again with the same logic
    //decided to represent it without a loop here since the shift is selfexplanatory
    u |= ((unsigned long)n.bytes[0]);
    u |= ((unsigned long)n.bytes[1]) << 8;
    u |= ((unsigned long)n.bytes[2]) << 16;
    u |= ((unsigned long)n.bytes[3]) << 24;

    if (n.bytes[3] & 0x80)          // if negative
        u |= 0xFFFFFFFF00000000UL;  // fill upper 32 bits with 1s
    return (long)u;
}

unsigned char myint32_is_negative(myint32 n){
    return (n.bytes[3] >> 7) & 1;
}

myint32 myint32_add(myint32 n, myint32 b);

myint32 myint32_negate(myint32 n){
    myint32 flipped, one;
    int i;
    for(i=0; i<4; i++){
        flipped.bytes[i] = n.bytes[i] ^ 0xFF; //XORING the whole byte logic
    }
    
    one = myint32_from(1);
    return myint32_add(flipped, one); //due to the twos complement magic ;)
}

myint32 myint32_add(myint32 a, myint32 b){
    myint32 result;
    unsigned int carry = 0;
    int i;
    for(i=0;i<4;i++){
        unsigned int sum = (unsigned int)a.bytes[i] + (unsigned int)b.bytes[i] + carry;

        result.bytes[i] = (unsigned char) (sum & 0xFF);
        carry = sum >> 8;
    }
    return result;
}

myint32 myint32_sub(myint32 a, myint32 b){
    return myint32_add(a, myint32_negate(b)); //creative way, instead of boring a-b we say a+(-b)
}


myint32 myint32_inc(myint32 n) { 
    return myint32_add(n, myint32_from(1)); 
}
myint32 myint32_dec(myint32 n) { 
    return myint32_sub(n, myint32_from(1)); 
}
