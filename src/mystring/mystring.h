#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>

size_t my_strlen(const char* s);

char *my_strcpy(char *dest, const char *src);

char *my_strncpy(char *dest, const char *src, int n);

char *my_strcat(char *dest, const char *arc);

int my_strcmp(const char *a, const char *b);

char *my_strdup(const char *s);

#endif