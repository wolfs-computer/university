#include <stdio.h>


int reverse(int number) {
    int re_number = 0;
    int k = 0;

    while (number != 0) {
        re_number *= 10;
        k = number % 10;
        re_number += k;
        number /= 10;
    }

    return re_number;
}


int is_palindrom(int number) {
    int re_number = reverse(number);

    while (number != 0 || re_number != 0) {
        if (number % 10 != re_number % 10) {
            return 0;
        }

        number /= 10;
        re_number /= 10;
    }

    return 1;
}



int main() {

    int number;
    scanf("%d", &number);
    // int number = 10101;


    if (is_palindrom(number)) {
        printf("is palindrom\n");
    } else {
        printf("not palindrom\n");
    }



    return 0;
}
