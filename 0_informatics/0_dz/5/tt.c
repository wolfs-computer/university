#include <stdio.h>
#include <math.h>



int main() {

    int min = 999999;

    int num;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &num);
        if (num < min) min = num;
    }

    printf("%d\n", min);



    return 0;
}
