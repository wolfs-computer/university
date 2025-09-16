// #include <string.h>
#include <stdio.h>



/* ###############################################=-> string manipulation <-=############################################### */



/*
Copies the null-terminated byte string pointed to by src, including the null terminator,
to the character array whose first element is pointed to by dest.
*/
char *strcpy(char *dest, const char *src);

char *my_strcpy(char *dest, const char *src) {
    int i = 0;
    
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }

    return dest;
}


/*
Copies at most count characters of the character array pointed to by src
(including the terminating null character, but not any of the characters that follow the null character)
to character array pointed to by dest.

If count is reached before the entire array src was copied, the resulting character array is not null-terminated.
*/
char *strncpy(char *dest, const char *src, size_t count);



/*
Appends a copy of the null-terminated byte string pointed to by src to the end of the null-terminated byte string pointed to by dest.
The character src[0] replaces the null terminator at the end of dest.
The resulting byte string is null-terminated.
*/
char *strcat(char *dest, const char *src);

char *my_strcat(char *dest, const char *src) {
    char *ptr = dest;
    
    while (*dest) dest++;

    while ((*dest++ = *src++));

    return ptr;
}


/*
Appends at most count characters from the character array pointed to by src, stopping if the null character is found,
to the end of the null-terminated byte string pointed to by dest.
The character src[0] replaces the null terminator at the end of dest.
The terminating null character is always appended in the end (so the maximum number of bytes the function may write is count+1).
*/
char *strncat(char *dest, const char *src, size_t count);



/*
Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by src.
The space for the new string is obtained as if the malloc was invoked.
The returned pointer must be passed to free to avoid a memory leak. 
*/
char *strdup(const char *src);
char *strndup(const char *src, size_t size);



/* ###############################################=-> string examination <-=############################################### */


/*
Returns the length of the given null-terminated byte string,
that is, the number of characters in a character array whose first element is pointed to by str up to and not including the first null character.
*/
size_t strlen(const char *str);

size_t my_strlen(const char *s) {
    int res = 0;

    while (*s) {
        ++s;
        ++res;
    }

    return res;
}



/*
Compares two null-terminated byte strings lexicographically.

The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as unsigned char) that differ in the strings being compared. 


Negative value -- if lhs appears before rhs in lexicographical order.

Zero -- if lhs and rhs compare equal.

Positive value -- if lhs appears after rhs in lexicographical order. (lhs > rhs)
*/
int strcmp(const char *lhs, const char *rhs);

int strncmp(const char *lhs, const char *rhs, size_t count);



/*
same as strcmp
respects LC_COLLATE
*/
int strcoll( const char *lhs, const char* rhs );



/*
Finds the FIRST occurrence of ch (after conversion to char as if by (char)ch)
in the null-terminated byte string pointed to by str (each character interpreted as unsigned char).

The terminating null character is considered to be a part of the string and can be found when searching for '\0'.
*/
char *strchr(const char *str, int ch);



/*
Finds the LAST occurrence of ch (after conversion to char as if by (char)ch) in the null-terminated byte string pointed to by str (each character interpreted as unsigned char). The terminating null character is considered to be a part of the string and can be found if searching for '\0'.
*/
char *strrchar(const char *str, int ch);



/*
Returns the length of the maximum initial segment (span) of the null-terminated byte string pointed to by dest,
that consists of only the characters found in the null-terminated byte string pointed to by src.

The behavior is undefined if either dest or src is not a pointer to a null-terminated byte string. 
*/
size_t strspn(const char *dest, const char *src);



/*
Returns the length of the maximum initial segment of the null-terminated byte string pointed to by dest,
that consists of only the characters NOT found in the null-terminated byte string pointed to by src. 
*/
size_t strcspn(const char *dest, const char *src);



/*
The name stands for "string pointer break", because it returns a pointer to the first of the separator ("break") characters. 


Scans the null-terminated byte string pointed to by dest for any character from the null-terminated byte string pointed to by breakset,
and returns a pointer to that character.
*/
char *strpbrk(const char *dest, const char *breakset);



/*
Finds the first occurrence of the null-terminated byte string pointed to by substr in the null-terminated byte string pointed to by str.

The terminating null characters are not compared.


Pointer to the first character of the found substring in str, or a null pointer if such substring is not found.
If substr points to an empty string, str is returned. 
*/
char *strstr(const char *str, const char *substr);



/*
Tokenizes a null-terminated byte string.


A sequence of calls to strtok breaks the string pointed to by str into a sequence of tokens,
each of which is delimited by a character from the string pointed to by delim.
Each call in the sequence has a search target:

    If str is non-null, the call is the first call in the sequence. The search target is null-terminated byte string pointed to by str.
    If str is null, the call is one of the subsequent calls in the sequence. The search target is determined by the previous call in the sequence.

Each call in the sequence searches the search target for the first character that is not contained in the separator string pointed to by delim, the separator string can be different from call to call.

    If no such character is found, then there are no tokens in the search target. The search target for the next call in the sequence is unchanged.[1]
    If such a character is found, it is the start of the current token. strtok then searches from there for the first character that is contained in the separator string.
        If no such character is found, the current token extends to the end of search target. The search target for the next call in the sequence is an empty string.[2]
        If such a character is found, it is overwritten by a null character, which terminates the current token. The search target for the next call in the sequence starts from the following character.

*/
char *strtok(char *str, const char *delim);


int check_delim(const char *delim, const char c) {
    while (*delim) {
        if (*delim == c) return 1;
        delim++;
    }
    return 0;
}

char *my_strtok(char *s, const char *delim) {

    static char* str;

    if (s != NULL) str = s;

    if (!delim || *str == '\0') return NULL;

    while (*str != '\0' && check_delim(delim, *str)) str++;

    if (*str == '\0') return NULL;

    char *token = str;
    str++;

    while (*str != '\0' && !check_delim(delim, *str)) str++;

    if (*str != '\0') {
        *str = '\0';
        str++;
    }

    return token;
}



/* ###############################################=-> Character array manipulation <-=############################################### */



/*
This function behaves as if it reads the bytes sequentially and stops as soon as a matching bytes is found:
if the array pointed to by ptr is smaller than count,
but the match is found within the array, the behavior is well-defined. 


Pointer to the location of the byte, or a null pointer if no such byte is found. 
*/
void *memchr(const void *ptr, int ch, size_t count);



/*
Compares the first count bytes of the objects pointed to by lhs and rhs. The comparison is done lexicographically.

The sign of the result is the sign of the difference between the values of the first pair of bytes (both interpreted as unsigned char) that differ in the objects being compared.

The behavior is undefined if access occurs beyond the end of either object pointed to by lhs and rhs. The behavior is undefined if either lhs or rhs is a null pointer. 


Negative value if lhs appears before rhs in lexicographical order.

Zero if lhs and rhs compare equal, or if count is zero.

Positive value if lhs appears after rhs in lexicographical order. (lhs > rhs)
*/
int memcmp(const void *lhs, const void *rhs, size_t count);



/*
Copies the value (unsigned char)ch into each of the first count characters of the object pointed to by dest.
The behavior is undefined if access occurs beyond the end of the dest array. The behavior is undefined if dest is a null pointer.
*/
void my_memset(void *dest, int ch, size_t count);



/*
Copies count characters from the object pointed to by src to the object pointed to by dest.
Both objects are interpreted as arrays of unsigned char.

The behavior is undefined if access occurs beyond the end of the dest array.
If the objects overlap (which is a violation of the restrict contract)(since C99), the behavior is undefined.
The behavior is undefined if either dest or src is an invalid or null pointer.
*/
void *memcpy(void *dest, const void *src, size_t count);



/*
Copies count characters from the object pointed to by src to the object pointed to by dest.
Both objects are interpreted as arrays of unsigned char.

The objects may overlap: copying takes place as if the characters were copied to a temporary character array and then the characters were copied from the array to dest.

The behavior is undefined if access occurs beyond the end of the dest array. The behavior is undefined if either dest or src is an invalid or null pointer.
*/
void *memmove(void *dest, const void *src, size_t count);
