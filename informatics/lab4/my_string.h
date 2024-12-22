#ifndef _MY_STRING_H_
#define _MY_STRING_H_


#include <stddef.h>


char *readline (const char *);

size_t strlen (const char *s);
char *strcat (char *dest, const char *src);
char *strtok (char *s, const char *delim);
char *strcpy (char *dest, const char *src);


#endif
