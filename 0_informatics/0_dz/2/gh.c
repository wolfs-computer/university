#include <stdio.h>


int main() {

    float x, y;

    printf("Simple if program.\n");
    printf("Enter variable x: ");
    scanf("%f", &x);

    if ((x >= 0) && (x <= 14)) {
        y = x - 12;
    } else if (x > 14) {
        y = x * x;
    } else {
        y = 0;
    }

    printf("x=%f, y=%f\n", x, y);


    return 0;
}
