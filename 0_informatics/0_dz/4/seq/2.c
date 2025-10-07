#include <stdio.h>
#include <math.h>



double factorial(int num) {
    double result = num;
    for (int i = 2; i < num; i++) {
        result *= i;
    }
    return result;
}


int main() {

    int n;
    scanf("%d", &n);
    double num;
    scanf("%lf", &num);

    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += pow(-1, i) * pow(num, 2 * i + 1) / factorial(2 * i + 1);
    }

    printf("%lf\n", sum);
    // n
    // 3
    // 0.141120
    // n
    // 1.57
    // 0.100000


    return 0;
}
