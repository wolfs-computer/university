#include <stdio.h>



int main() {
    int a, b, c;
    while (1) {
        printf("Enter 3 unique numbers: ");
        scanf("%d %d %d", &a, &b, &c);

        // check if all unique
        if ((a != b) && (a != c) && (b != c)) {
            break;
        }
        printf("Wrong!");
    }

    int max1, max2;
    if (a > b) {
        max1 = a;
        max2 = b;
    } else {
        max1 = b;
        max2 = a;
    }

    int max3;
    if (max1 > c) {
        if (max2 > c) {
            max3 = c;
        } else {
            max3 = max2;
            max2 = c;
        }
    } else {
        max3 = max2;
        max2 = max1;
        max1 = c;
    }

    printf("%d %d %d\n", max1, max2, max3);


    return 0;
}
