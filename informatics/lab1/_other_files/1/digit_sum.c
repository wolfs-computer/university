#include <stdio.h>


int dsum(int num) {

    int sum = 0;

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }


    return sum;
}



int main() {

    int num;
    scanf("%d", &num);

    int r = dsum(num);

    printf("Result: %d\n", r);


    return 0;
}
