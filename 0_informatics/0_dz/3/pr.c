#include <stdio.h>



int main() {

    int a, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);

        // check if all unique
        if ((a != b) && (a != c) && (b != c)) {
            break;
        }
    }


    return 0;
}
