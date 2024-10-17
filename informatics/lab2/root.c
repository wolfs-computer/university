#include <stdio.h>
#include <math.h>



long double root_of(int a, int n, int row_count) {

    long double y = a;

    for (int i = 0; i < row_count; i++) {

        y = (1 / (long double) n) * ((n - 1) * y + (a / pow(y, n - 1)));

        // printf("%Lf\n", y);
    }


    return y;
}


int main() {

    int a = -1;
    int n = -1;
    int row_count = -1;

    scanf("%d", &a);
    scanf("%d", &n);
    scanf("%d", &row_count);

    // check input
    if (a <= -1 || n <= -1 || row_count <= -1) {
        printf("Error: invalid input!\n");
        return 1;
    }


    // printf("%Lf\n", root_of(20, 2, 5));
    printf("%Lf\n", root_of(a, n, row_count));



    return 0;
}
