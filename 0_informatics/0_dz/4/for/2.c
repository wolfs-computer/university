#include <stdio.h>
#include <math.h>



int main() {

    int r1;
    int r2;
    scanf("%d %d", &r1, &r2);

    int min, max;
    if (r1 > r2) {
        max = r1;
        min = r2;
    } else {
        max = r2;
        min = r1;
    }

    for (int i = min; i <= max; i++) {
        printf("x=%d -> y=%d\n", i, (int) pow(i, 2) + 1);
    }


    return 0;
}
