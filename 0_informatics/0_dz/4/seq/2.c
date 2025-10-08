#include <stdio.h>
#include <math.h>



double factorial(int num) {
    double result = num;
    for (int i = 2; i < num; i++) {
        result *= i;
    }
    return result;
}



void pre() {
    int n;
    scanf("%d", &n);
    double num;
    scanf("%lf", &num);

    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += pow(-1, i) * pow(num, 2 * i + 1) / factorial(2 * i + 1);
    }

    printf("%lf\n", sum);
}

void post() {
    int n;
    scanf("%d", &n);
    double num;
    scanf("%lf", &num);

    double sum = 0;
    int i = 0;
    do {
        sum += pow(-1, i) * pow(num, 2 * i + 1) / factorial(2 * i + 1);
        i++;
    } while (i <= n);

    printf("%lf\n", sum);
}


int main() {

    // pre();
    post();

    // n
    // 3
    // 0.141120
    // n
    // 1.57
    // 1.000000


    return 0;
}
