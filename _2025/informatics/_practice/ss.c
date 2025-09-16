#include <stdio.h>


int convert(int num, int base) {
    int result = 0;
    int i = 1;

    while (num != 0) {
        result += (num % base) * i;
        num /= base;
        i *= 10;
    }

    return result;
}

long double convert_dot(long double num, int base) {
    long double result = 0;

    long double i = 0.1;

    while (num != 0.0) {
        long double tmp = (long double)((int) (num * base));
        result += tmp * i;
        num = num * base - tmp;

        i /= 10;

        /* printf("%Lf %Lf %Lf %Lf\n", tmp, result, num, i); */
    }

    return result;
}



int main() {

    int num = 85;
    int base = 2;


    printf("%d\n", convert(num, base));

    long double n = 0.125;

    printf("%Lf\n", convert_dot(n, base));



    return 0;
}
