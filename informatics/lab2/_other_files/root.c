#include <stdio.h>
#include <math.h>



int get_input(int *number) {

    int input_status = scanf("%d", number);
    /* printf("%d %d\n", *number, input_status); */

    if (input_status == EOF) {
        printf("\nEOF!\n");
        return 3;
    }

    while (getchar() != '\n'); // clean input buffer

    if (input_status != 1) {

        printf("Error: invalid input!\n");
        return 1;
    }

    if (*number < -1) {
        printf("Error: incorrect value!\n");
        return 2;
    }

    return 0;
}



long double root_of(int a, int n, int row_count) {

    long double y = a;

    for (int i = 0; i < row_count; i++) {

        y = (1 / (long double) n) * ((n - 1) * y + (a / pow(y, n - 1)));

        // printf("p1 - %Lf\n", (1 / (long double) n));
        // printf("p2 - %Lf\n", ((n - 1) * y + (a / pow(y, n - 1))));
        // printf("y - %Lf\n", y);


        // printf("%Lf\n", y);
    }


    return y;
}


int main() {

    int a = -2;
    int n = -2;
    int row_count = -2;


    int status = 0;
    for (int i = 0; i < 3; i++) {
        printf("Enter %d argument: ", i + 1);

        if (i == 0) status = get_input(&a);
        if (i == 1) status = get_input(&n);
        if (i == 2) status = get_input(&row_count);

        if (status == 3) return 0;
        if (status != 0) {
            i--;
            continue;
        }
    }
    /* printf("%d %d %d\n", a, n, row_count); */


    // printf("%Lf\n", root_of(20, 2, 5));
    printf("%Lf\n", root_of(a, n, row_count));



    return 0;
}
