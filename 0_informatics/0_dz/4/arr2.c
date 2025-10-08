#include <stdio.h>



int main() {

    int x, y;
    scanf("%d %d", &x, &y);

    int arr[x][y];

    for (int i = 0; i < x; i++) {
        for (int g = 0; g < y; g++) {
            scanf("%d", arr[i] + g);
        }
    }

    for (int i = 0; i < x; i++) {
        for (int g = 0; g < y; g++) {
            printf("%d ", arr[i][g]);
        }
        printf("\n");
    }



    return 0;
};
