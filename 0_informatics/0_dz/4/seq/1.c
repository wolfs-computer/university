#include <stdio.h>
#include <math.h>



int main() {

    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += i;
    }

    printf("%d\n", sum);


    return 0;
}
