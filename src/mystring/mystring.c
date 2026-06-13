#include "mystring.h"
#include <stdlib.h>
#include <stdio.h>
size_t my_strlen(const char* s)
{
    size_t len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}

char *my_strcpy(char *dest, const char *src){
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, const char *src, int n){
    int i = 0;
    while (i<n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, const char *src){
    size_t dest_len = my_strlen(dest);
    size_t src_len = my_strlen(src);
    size_t totallen = dest_len + src_len + 1;
    char *result = malloc(totallen);
    for(int i=0; i<dest_len; i++){
        result[i] = dest[i];
    }
    for(int i=0; i<src_len; i++){
        result[i+dest_len] = src[i];
    }
    result[totallen-1] = '\0';
    return result;
}

int my_strcmp(const char *a, const char *b){
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0'){
        if(a[i]>b[i]){ return 1; }
        if(a[i]<b[i]){ return -1; }
        i++;
    }
    return 0;
}

char *my_strdup(const char *s){
    int i = 0;
    char *string = malloc(my_strlen(s)+1);
    my_strcpy(string, s);
    return string;
}

int main(void){
    char stringa[] = "Hello";
    char stringb[] = "World";

    size_t lena = my_strlen(stringa);
    size_t lenb = my_strlen(stringb);
    size_t totalen = lena+lenb;

    char *copy = my_strdup(stringa);

    
    char *result = my_strncpy(copy, stringb, 4);
    printf("this is the result: %s\n", result);
    free(result);
    result = NULL;
    result = my_strcat(stringa, stringb);
    printf("this is the result: %s\n", result);
    free(result);
    result = NULL;

    int cmp = my_strcmp(stringa, stringb);
    if(cmp==1){
        printf("%s is greater than %s", stringa, stringb);
    }
    if(cmp==-1){
        printf("%s is less than %s", stringa, stringb);
    }
    if(cmp==0){
        printf("both %s and %s are equal", stringa, stringb);
    }

    free(copy);
    copy = NULL;
    return 0;
}