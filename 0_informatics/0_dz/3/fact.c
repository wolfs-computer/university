#include <stdio.h>


int main() {
    int k;

    printf("Enter number: ");
    scanf("%d", &k);

    long p = 1;
    int n = 1;

    while (n <= k) {
        p *= n;
        n++;
    }

    printf("Factorial of p = %ld\n", p);

}
