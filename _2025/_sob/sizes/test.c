#include <stdio.h>
#include <limits.h>
#include <math.h>



/*

Category        Type            Minimum Size   Typical Size          Note
---------------------------------------------------------------------------------------------------
character       char            1 byte         1 byte                always exactly 1 byte
                wchar_t         1 byte         2 or 4 bytes
                char8_t         1 byte         1 byte
                char16_t        2 bytes        2 bytes
                char32_t        4 bytes        4 bytes
---------------------------------------------------------------------------------------------------
integer         short           2 bytes        2 bytes
                int             2 bytes        4 bytes
                long            4 bytes        4 or 8 bytes
                long long       8 bytes        8 bytes
---------------------------------------------------------------------------------------------------
floating point  float           4 bytes        4 bytes
                double          8 bytes        8 bytes
                long double     8 bytes        8, 12, or 16 bytes
*/



int main(int argc, char** argv) {


    printf("CHAR_BIT : %d\n", CHAR_BIT);

    printf("char        %d : %d\n", CHAR_MIN, CHAR_MAX);
    printf("int         %d : %d\n", INT_MIN, INT_MAX);
    printf("long int    %ld : %ld\n", (long) LONG_MIN, (long) LONG_MAX);

    // printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    // printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    // printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    // printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);


    int *a = NULL;
    printf("%d\n", sizeof(a));


    return 0;
}
