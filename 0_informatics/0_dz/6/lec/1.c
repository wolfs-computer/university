#include <stdio.h>


void nod1() {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    printf("%d\n", a);
}

void nod2() {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }

    if (a == 0) {
        printf("%d\n", b);
    } else {
        printf("%d\n", a);
    }
}


int main() {

    nod2();


    return 0;
}
