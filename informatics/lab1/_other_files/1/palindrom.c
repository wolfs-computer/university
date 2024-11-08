#include <stdio.h>


int reverse(int num) {
    int rnum = 0;
    int k = 0;

    while (num != 0) {
        rnum *= 10;
        k = num % 10;
        rnum += k;
        num /= 10;
    }

    return rnum;
}


int isP(int num) {
    int rnum = reverse(num);

    while (num != 0 || rnum != 0) {
        if (num % 10 != rnum % 10) {
            return 0;
        }

        num /= 10;
        rnum /= 10;
    }

    return 1;
}



int main() {

    int num;
    scanf("%d", &num);

    int r = isP(num);

    if (r == 1) {
        printf("is palindrom\n");
    } else {
        printf("not palindrom\n");
    }



    return 0;
}
