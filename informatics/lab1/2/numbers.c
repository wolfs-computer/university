#include <stdio.h>


// check if number is simple
int check(int num) {

    for (int i = 2; i * i <= num; i++) {

        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}


// print every simple number before num
void find_s(int num) {

    int i = 2;

    while (i < num) {
        int ch = check(i);

        // if number is simple
        if (ch == 1) {
            printf("%d\n", i);
        }

        i++;
    }
}



int main() {

    int num = -1;
    scanf("%d", &num);

    // check input
    if (num <= -1) {
        printf("Error: invalid input!\n");
        return 1;
    }


    find_s(num);



    return 0;
}
