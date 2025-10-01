#include <stdio.h>



int main() {
    int a, b, c, d;
    while (1) {
        scanf("%d %d %d %d", &a, &b, &c, &d);

        // check if all unique
        if ((a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d)) {
            break;
        }
    }

    int max1, max2, max3;

    int tmp;
    if (a < b) {tmp = a; a = b; b = tmp;};
    if (b < c) {tmp = b; b = c; c = tmp;};
    if (a < b) {tmp = a; a = b; b = tmp;};

    if (c < d) {tmp = c; c = d; d = tmp;};
    if (b < c) {tmp = b; b = c; c = tmp;};
    if (a < b) {tmp = a; a = b; b = tmp;};

    printf("%d %d %d %d\n", a, b, c, d);


    return 0;
}
