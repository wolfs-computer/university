#include <stdio.h>



int sum(int num, int k, int *result) {

    *result = 0;
    int i = 1;
    int from_prev = 0;

    while (num != 0) {
        // 219

        int first_digit = num % 10; 
        num /= 10;

        int s = first_digit + k + from_prev;
        /* printf("%d", s); */
        *result += (s % 10) * i;
        from_prev = s / 10;
        
        i *= 10;

        printf("%d %d %d\n", first_digit, from_prev, *result);
    }

    return from_prev;
}


int main() {

    int num;
    int k;

    /* scanf("%d", &num); */
    /* scanf("%d", &k); */
    num = 11;
    k = 9;

    int result = 0;

    int overflow = sum(num, k, &result);

    printf("%d %d\n", result, overflow);




    return 0;
}
