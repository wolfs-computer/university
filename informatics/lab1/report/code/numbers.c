#include <stdio.h>
#include <math.h>


int check(int num) {

    int num_root = sqrt(num);

    for (int i = 2; i <= num_root; i++) {

        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void find_s(int num) {

    int i = 2;

    while (i < num) {
        int ch = check(i);

        if (ch == 1) {
            printf("%d\n", i);
        }

        i++;
    }
}


int main() {

    int num = -1;
    scanf("%d", &num);

    if (num <= -1) {
        printf("Error: invalid input!\n");
        return 1;
    }

    find_s(num);

    return 0;
}
