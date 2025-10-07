#include <stdio.h>
#include <math.h>



int main() {

    double num;
    double sum = 0;
    for (int i = 1; i < 6; i++) {
        scanf("%lf", &num);
        sum += num;
        printf("%lf\n", sum / i);
    }


    return 0;
}
