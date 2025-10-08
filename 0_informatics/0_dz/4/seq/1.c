#include <stdio.h>
#include <math.h>


void pre() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += i;
    }

    printf("%d\n", sum);
}


void post() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    int i = n;
    do {
        sum += i;
        i--;
    } while (i > 0);

    printf("%d\n", sum);
}


int main() {

    // pre();
    post();



    return 0;
}
