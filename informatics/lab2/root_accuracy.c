#include <stdio.h>
#include <math.h>



long double my_mod(long double num) {

    return (num < 0) ? -num : num;
}


int check_root_acc(int a, int n, long double acc, long double current_root) {

    return !(my_mod(a - pow(current_root, n)) <= acc);

}


void acc_root_of(int a, int n, long double acc) {

    int row_count = 0;
    long double y = a;

    for (int i = 0; check_root_acc(a, n, acc, y); i++) {

        y = (1 / (long double) n) * ((n - 1) * y + ((long double) a / pow(y, n - 1)));

        row_count++;

        // printf("%Lf\n", y);
    }

    printf("Row count: %d\n", row_count);
    printf("Result: %Lf\n", y);
}


int main() {

    int a = -1;
    int n = -1;
    long double acc = -1;

    scanf("%d", &a);
    scanf("%d", &n);
    scanf("%Lf", &acc);

    // check input
    if (a <= -1 || n <= -1 || acc <= -1) {
        printf("Error: invalid input!\n");
        return 1;
    }


    acc_root_of(30, 2, 0.001);
    // good for accuracy check numbers: 30



    return 0;
}
