#include <stdio.h>



int main() {

    const int len = 7;

    int arr1[len];
    int arr2[len];
    const int len_r = len * 2;
    int result[len * 2];

    // arr1
    for (int i = 0; i < len; i++) {
        scanf("%d", arr1 + i);
    }

    // arr2
    for (int i = 0; i < len; i++) {
        scanf("%d", arr2 + i);
    }

    // concat
    for (int i = 0; i < len; i++) {
        result[i * 2] = arr1[i];
        result[i * 2 + 1] = arr2[i];
    }

    // show
    for (int i = 0; i < len_r; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // sort
    for (int i = 0; i < len_r; i++) {
        for (int g = 0; g < len_r - i - 1; g++) {
            if (result[g] > result[g + 1]) {
                int tmp = result[g];
                result[g] = result[g + 1];
                result[g + 1] = tmp;
            }
        }
    }

    // show
    for (int i = 0; i < len_r; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");



    return 0;
}
