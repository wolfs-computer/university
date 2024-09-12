#include <stdio.h>


int get_digit_sum(int number) {

    int sum = 0;

    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }


    return sum;
}



int main() {

    int number;
    scanf("%d", &number);


    printf("Result: %d\n", get_digit_sum(number));


    return 0;
}
