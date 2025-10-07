#include <stdio.h>
#include <math.h>



int main() {

    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    int r;
    int d = 2;

    printf("%d\n", num);

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            printf("Not simple\n");
            return 0;
        }
    }
    printf("Simple\n");


    return 0;
}
