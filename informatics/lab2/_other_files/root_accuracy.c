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


long double ld_mod(long double num) {

    return (num < 0) ? -num : num;
}


int check_root_acc(int a, int n, int acc, long double current_root, long double next_root) {

    // printf("%d %d %d %Lf %Lf\n", a, n, acc, current_root, next_root);
    // printf("p1 = %Lf\n p2 = %Lf\n", next_root - current_root, powl(10, -(acc + 1)));
    // printf("%d\n", ld_mod(next_root - current_root) > pow(10, -(acc + 1)));

    return ld_mod(next_root - current_root) > pow(10, -(acc + 1));

}


long double acc_root_of(int a, int n, int acc, int *row_count) {

    if (a == 0) {
        return 0;
    }

    long double current_root = (1 / (long double) n) * ((n - 1) * a + ((long double) a / pow(a, n - 1)));
    long double next_root = (1 / (long double) n) * ((n - 1) * current_root + ((long double) a / powl(current_root, n - 1)));

    *row_count = 1;

    // printf("current_root = %Lf\n", current_root);
    // printf("next_root = %Lf\n", next_root);
    // printf("row_count = %d\n", *row_count);


    while (check_root_acc(a, n, acc, current_root, next_root)) {


        current_root = next_root;
        next_root = (1 / (long double) n) * ((n - 1) * current_root + ((long double) a / powl(current_root, n - 1)));

        (*row_count)++;

        // printf("check = 1");
        // printf("current_root = %Lf\n", current_root);
        // printf("next_root = %Lf\n", next_root);
        // printf("row_count = %d\n", *row_count);

        /* printf("%.19Lf\n", current_root); */
    }

    // solve sound problem
    
    long double bad_digit = (int)(current_root * powl(10, acc + 1)) % 10 * powl(10, -(acc + 1));
    /* printf(" %.19Lf\n", bad_digit); */
    current_root -= bad_digit;

    // printf("bad_digit = %Lf\n", bad_digit);
    // printf("current_root = %Lf\n", current_root);


    return current_root;
}


int main() {

    // input

    int a = -2;
    int n = -2;
    int acc = -2;

    int status = 0;
    for (int i = 0; i < 3; i++) {
        printf("Enter %d argument: ", i + 1);

        if (i == 0) status = get_input(&a);
        if (i == 1) status = get_input(&n);
        if (i == 2) status = get_input(&acc);

        if (status == 3) return 0;
        if (status != 0) {
            i--;
            continue;
        }
    }

    // good for accuracy check numbers: 30, 20
    /* a = 30; */
    /* n = 2; */
    /* acc = 20; */


    // main algorithm


    int row_count = 0;

    long double result = acc_root_of(a, n, acc, &row_count);


    printf("Number of rows: %d\n", row_count);
    printf("Result: %.*Lf\n", acc, result);



    return 0;
}
