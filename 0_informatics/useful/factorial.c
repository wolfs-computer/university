#include <stdio.h>



int main() {

    printf("Enter number: ");
    int num;
    scanf("%d", &num);

    long long result = 1;
    for (int i = 1; i < num + 1; i++) {
        result *= i;
        // printf("* %d\n", i);
    }

    printf("%lld\n", result);


    return 0;
}
