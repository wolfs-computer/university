#include <stdio.h>



void print_matrix(int matrix[4][10]) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 10; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}



int main() {

    int matrix[4][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {2, 2, 2, 2, 2, 2, 2, 2, 0, 2},
        {3, 3, 3, 3, 3, 3, 3, 0, 3, 3},
        {4, 4, 4, 4, 4, 4, 0, 4, 4, 4},
    };

    int k1 = 4;
    int k2 = 3;

    print_matrix(matrix);


    for (int i = 0; i < 10; i++) {
        int tmp = matrix[k1 - 1][i];
        matrix[k1 - 1][i] = matrix[k2 - 1][i];
        matrix[k2 - 1][i] = tmp;
    }


    print_matrix(matrix);


    return 0;
}
